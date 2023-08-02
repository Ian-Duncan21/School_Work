import csv
import os
import sys
import operator


def main():
    filename = sys.argv[1]
    quantum = int(sys.argv[2])

    data = readCSV(filename)

    fcfs([i.copy() for i in data])
    sjf([i.copy() for i in data])
    rr([i.copy() for i in data], quantum)

#read the CSV file and return the data
def readCSV(filename):
    reader = csv.DictReader(open(filename))
    data = [row for row in reader]
    for i in data:
        for key, val in i.items():
            i[key] = int(val)
    return data

#first come first serve
def fcfs(data):
    data.sort(key=lambda x: x['ProcessID'])
    data.sort(key=lambda x: x['Arrival Time'])
    for i in data:
        i['start'] = None
        i['end'] = None
    schedule = []

    #calculations for determining arrival of process
    time=0
    for i in data:
        if i['Arrival Time'] > time:
            schedule.append(ganttRow("IDLE", time, i['Arrival Time']))
            time = i['Arrival Time']
        i['start']=time
        i['end'] = time+int(i['Burst Time'])
        time = i['end']
        schedule.append(ganttRow(i['ProcessID'], i['start'], i['end']))

    processInfo = []
    for i in data:
        processInfo.append({
            "ProcessID": i["ProcessID"],
            "Waiting Time": i['start']-i['Arrival Time'],
            "Turnaround Time": i['end'] - i['Arrival Time']
        })

    printTable("FCFS", processInfo)
    printGantt("FCFS", schedule)
    nonPreemptive(processInfo)
    printAvg(processInfo, data)


#shortest job first
def sjf(data):
    for i in data:
        i['arrived'] = False
    data.sort(key=lambda x: x['ProcessID'])
    data.sort(key=lambda x: x['Arrival Time'])
    readyQueue = []
    schedule = []
    time = 0
    global running
    running = None
    maxArrivalTime = data[-1]['Arrival Time']+1
    idleProcess = None
    while time < maxArrivalTime or len(readyQueue) > 0: #loop for processes start
        for i in data:
            if i['Arrival Time'] <= time and i['arrived'] is False:
                readyQueue.append(i)
                i['arrived'] = True
        if len(readyQueue)>0:
            readyQueue.sort(key=lambda x: x['Burst Time'])
            running = readyQueue.pop(0)
        else:
            running = None
        if running:
            if idleProcess:
                schedule.append(idleProcess)
                idleProcess = None
            schedule.append(ganttRow(running['ProcessID'], time, time+running['Burst Time']))
            running['start'] = time
            running['end'] = time+running['Burst Time']
            time += running['Burst Time']
            running = None
            for i in data:
                if i['Arrival Time'] <= time and i['arrived'] is False:
                    readyQueue.append(i)
                    i['arrived'] = True
        else:
            if not idleProcess:
                idleProcess = ganttRow('IDLE', time, time)
            idleProcess['end']+=1
            time += 1

    processInfo = []
    for i in data:
        processInfo.append({
            "ProcessID": i["ProcessID"],
            "Waiting Time": i['start'] - i['Arrival Time'],
            "Turnaround Time": i['end'] - i['Arrival Time']
        })
    printTable("SJF", processInfo)
    printGantt("SJF", schedule)
    nonPreemptive(processInfo)
    printAvg(processInfo, data)

#round robin scheduling
def rr(data, quantum):
    for i in data:
        i['arrived'] = False
        i['start'] = None
        i['end'] = None
        i['remainingBurst'] = i['Burst Time']
        i['lastEnd'] = i['Arrival Time']
        i['waitTime'] = 0
    data.sort(key=lambda x: x['ProcessID'])
    data.sort(key=lambda x: x['Arrival Time'])
    queue = []
    schedule = []
    time =0
    maxArrivalTime = data[-1]['Arrival Time']
    global running
    running = False
    idle = False
    while time <= maxArrivalTime or len(queue) > 0:
        
        # check for and get newly arrived processes
        for i in data:
            if i['Arrival Time'] <= time and i['arrived'] is False:
                queue.append(i)
                i['arrived'] = True

        if len(queue)>0:
            running = queue.pop(0)
        else:
            running = None
        if running:
            reAdd = None
            if idle:
                schedule.append(idle)
                idle = None
            runTime = min(running['remainingBurst'], quantum)
            running['remainingBurst'] -= runTime
            schedule.append(ganttRow(running['ProcessID'], time, time+runTime))
            running['waitTime'] += time-running['lastEnd']
            running['lastEnd'] = time+runTime
            if running['start'] is None:
                running['start'] = time
            if running['remainingBurst'] == 0:
                running['end'] = time+runTime
            else:
                reAdd = running

            #get any new processes that might've showed up so loop doesn't end
            time += runTime
            running = None
            for i in data:
                if i['Arrival Time'] <= time and i['arrived'] is False:
                    queue.append(i)
                    i['arrived'] = True
            if reAdd:
                queue.append(reAdd)
        else:
            if not idle:
                idle = ganttRow('IDLE', time, time)
            idle['end']+=1
            time += 1

    processInfo = []
    for i in data:
        processInfo.append({
            "ProcessID": i["ProcessID"],
            "Waiting Time": i['start'] - i['Arrival Time'],
            "Turnaround Time": i['end'] - i['Arrival Time']
        })


    printTable("Round Robin", processInfo)
    printGantt("Round Robin", schedule)
    preemptive(data)
    printAvg(processInfo, data)

def ganttRow(id, start, end):
    return {
        "ProcessID": id,
        "start": start,
        "end": end
    }

#print the averages
def printAvg(processInfo, data):
    avgTurn = float(sum(i['Turnaround Time'] for i in processInfo)) / len(processInfo)
    tp = float(len(processInfo)) / data[-1]['end']
    print("Average Turnaround Time:", avgTurn)
    print("Throughput:", tp, '\n')
    #print('\n')
    
#print the gantt charts
def printGantt(schedName, data):
    print(schedName, "Gantt chart")
    for i in data:
        print("[{:^4}]--[{:^4}]--[{:^4}]".format(i['start'], i['ProcessID'], i['end']))

#print the tables
def printTable(schedName, tableData):
    print("_"*20, schedName, "_"*20)
    longest = max([len(schedName) for schedName in tableData[0].keys()])
    row_format = "{:^"+str(longest)+"} | "
    row_format *= (len(tableData[0].values()))
    print(row_format.format(*tuple(tableData[0].keys())))
    for process in tableData:
        print(row_format.format(*tuple(process.values())))
    
#print average times based on preemptive or nonPreemptive algorithm   
def nonPreemptive(processInfo):
    print("Average Waiting Time:", float(sum(i['Waiting Time'] for i in processInfo)) / len(processInfo))
    
def preemptive(data):
    print("Average Waiting Time:", (sum(i['waitTime'] for i in data)) / len(data))


if __name__ == '__main__':
    main()
