.orig x3000
JSR TOUPPER
JSR TOUPPER ;Yes call it twice.
PUTS
HALT

TOUPPER		ST R0, VAR_0
			ST R1, VAR_1
			ST R2, VAR_2
			ST R3, VAR_3
			ST R4, VAR_4
			ST R5, VAR_5
			ST R6, VAR_6
			ST R7, VAR_7
			LD R4, NEG_96
			LD R5, NEG_123
			LD R6, NEG_32
		
			ADD R1, R0, #0	

            RET

VAR_0		.fill 0
VAR_1		.fill 0
VAR_2		.fill 0
VAR_3		.fill 0
VAR_4		.fill 0
VAR_5		.fill 0
VAR_6		.fill 0
VAR_7		.fill 0
NEG_96		.fill -96
NEG_123		.fill -123
NEG_32		 .fill -32

		    .end