   #include<iostream>

   using namespace std;

   int main(int argc, char *argv[]){
   (void)argc;
   int numSize = 100;
   int num[100] = {0};
   int x;
   int lastIndex = 0;

    while(cin >> x){
      if(x < 0 || x >= numSize){
	cerr << argv[0] << "Error: Input out of range 0-99\n";
	exit(EXIT_FAILURE);
      }else{
      num[x]++;
        if(x > lastIndex){
           lastIndex = x;
        }
      }  
    }


    for(int i = 0; i <= lastIndex; i++){
       if(num[i] > 0){
          cout << i << "x" << num[i] << " ";
       }
    }

    cout << '\n';

    for(int i = 0; i <= lastIndex; i++){
       if(num[i] > 0){
          for(int j = 0; j < num[i]; j++){
             if(i == lastIndex && j == 1){
                cout << i;
             } else {
                cout << i << ",";
             }
          }
       }
    }

    cout << '\n';
    return 0;
}
