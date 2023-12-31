    ; Recitation MoreLC3
    ; Author: <name>
    ; Date:   <date>
    ; Email:  <email>
    ; Class:  CS270
    ; Description: Mirrors least significant byte to most significant

                    .ORIG x3000

                    JSR mirror           ; call function
                    HALT

    ; Parameter and return value
    Param           .BLKW 1              ; space to specify parameter
    Result          .BLKW 1              ; space to store result

    ; Constants
    One             .FILL #1             ; the number 1       
    Eight           .FILL #8             ; the number 8
    Mask            .FILL x00ff          ; mask top bits

    ;--------------------------------------------------------------------------
mirror                                   ; Mirrors bits 7:0 to 15:8
                                         ; ~20 lines of assembly code
     
                    LD R0,Param          ; load pattern
                    ADD R1,R0,#0
		    LD R2,Mask
		    AND R1,R1,R2
		    LD R2,One
		    LD R3,One
		    LD R4,Eight
loopIncrement
		    ADD R3,R3,R3
		    ADD R4,R4,#-1
		    BRp loopIncrement
		    LD R4,Eight

loopMask
		    AND R5,R0,R2
		    BRz compiler
		    ADD R1,R3,R1

compiler
	  	    ADD R2,R2,R2
		    ADD R3,R3,R3
		    ADD R4,R4,#-1
		    BRp loopMask
		                         ; your code here
                    ST R1,Result         ; store result
                    RET
    ;--------------------------------------------------------------------------
                   .END
