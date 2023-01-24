            .orig x3000
            LEA R0, STR1 ;R0 points to STR1
            JSR FINDLAST ;Find the address of the last character in the string
            PUTS ;Should print only the last character of STR1
            HALT

FINDLAST	ST R7, VAR_7
		    ST R1, VAR_1
		    ST R2, VAR_2

		    ADD R2, R0, #0
		    LDR R0, R2, #0
		    BRZ GETOUT

TP		    ADD R2, R2, #1
		    LDR R0, R2, #0
		    BRZ GETLAST
		    BRNZP TP

GETLAST		ADD R2, R2, #-1
		    ADD R0, R2, #0

GETOUT		LD R7, VAR_7
		    LD R1, VAR_1
		    LD R2, VAR_2

		    RET





            ;Data – Change these for testing
            .blkw 100 ;Change this value when testing between 50 and 150.
            STR1 .stringz "abCDefG5" ;Use numbers, punctuation, spaces, etc... while testing.

VAR_7		.fill 0
VAR_1		.fill 0
VAR_2		.fill 0
            .end