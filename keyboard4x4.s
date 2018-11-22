;==============================================================================
; keyboard4x4.s
; Luís Henrique Beltrão Santana
; 12/10/2018
;==============================================================================

;==============================================================================
        THUMB                        ; Instruções do tipo Thumb-2
;==============================================================================
		

; Define

;==============================================================================
; Data
;==============================================================================
		AREA DATA, ALIGN=2
keyboard_0404_map	SPACE 4

;==============================================================================
; Code
;==============================================================================
        AREA |.text|, CODE, READONLY, ALIGN=2
		EXPORT init_kb_m0404_00
		EXPORT kb_m0404_00
		IMPORT  SysTick_Wait1ms
		IMPORT PortC_Input
		IMPORT PortK_Output
		IMPORT PortL_Output
		IMPORT PortM_Output

;==============================================================================
; Start
;==============================================================================

; kb-m0404-00

init_kb_m0404_00
		PUSH	{R1, R2}
		LDR 	R1, =keyboard_0404_map
		MOV 	R2, #0x7
		STRB	R2, [R1], #1
		MOV 	R2, #0xB
		STRB	R2, [R1], #1
		MOV 	R2, #0xD
		STRB	R2, [R1], #1
		MOV 	R2, #0xE
		STRB	R2, [R1], #1
		POP		{R1, R2}
		BX 		LR

kb_m0404_00
		PUSH	{R1, R2, R8, LR}
		LDR 	R1, =keyboard_0404_map
		MOV		R2, #0
kb_m0404_00_loop
		LDR		R10, [R1,R2]				; R10 <- R1[R2]
		BL		PortL_Output				; PortL <- R10
		BL		PortC_Input					; R8 <- PortC
		MOV		R4, R8						; R4 <- R8
		MOV 	R0, #10						; set time to bounce delay
		BL 		SysTick_Wait1ms				; delay
		BL		PortC_Input					; R8 <- PortC
		BIC		R4, #0xF
		BIC		R8, #0xF
		CMP		R8, #0
		BEQ		kb_m0404_00_jump
		CMP		R4, R8						; compare R4 and R8
		BEQ		kb_m0404_00_analyze
kb_m0404_00_jump
		ADD		R2, #1						; R2++
		CMP		R2, #4						; compare R2 and 4
		BNE		kb_m0404_00_loop
kb_m0404_00_continue
		POP		{R1, R2, R8, LR}
		BX 		LR
		
kb_m0404_00_analyze
		CMP		R8, # 0x70
		BEQ		kb_m0404_00_analyze_7
		CMP		R8, # 0xB0
		BEQ		kb_m0404_00_analyze_B
		CMP		R8, # 0xD0
		BEQ		kb_m0404_00_analyze_D
		CMP		R8, # 0xE0
		BEQ		kb_m0404_00_analyze_E
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_7
		CMP		R3, # 0x7
		BEQ		kb_m0404_00_analyze_77
		CMP		R3, # 0xB
		BEQ		kb_m0404_00_analyze_7B
		CMP		R3, # 0xD
		BEQ		kb_m0404_00_analyze_7D
		CMP		R3, # 0xE
		BEQ		kb_m0404_00_analyze_7E
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_B
		CMP		R3, # 0x7
		BEQ		kb_m0404_00_analyze_B7
		CMP		R3, # 0xB
		BEQ		kb_m0404_00_analyze_BB
		CMP		R3, # 0xD
		BEQ		kb_m0404_00_analyze_BD
		CMP		R3, # 0xE
		BEQ		kb_m0404_00_analyze_BE
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_D
		CMP		R3, # 0x7
		BEQ		kb_m0404_00_analyze_D7
		CMP		R3, # 0xB
		BEQ		kb_m0404_00_analyze_DB
		CMP		R3, # 0xD
		BEQ		kb_m0404_00_analyze_DD
		CMP		R3, # 0xE
		BEQ		kb_m0404_00_analyze_DE
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_E
		CMP		R3, # 0x7
		BEQ		kb_m0404_00_analyze_E7
		CMP		R3, # 0xB
		BEQ		kb_m0404_00_analyze_EB
		CMP		R3, # 0xD
		BEQ		kb_m0404_00_analyze_ED
		CMP		R3, # 0xE
		BEQ		kb_m0404_00_analyze_EE
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_77
		MOV		R0, #1
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_7B
		MOV		R0, #2
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_7D
		MOV		R0, #3
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_7E
		MOV		R0, #10
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_B7
		MOV		R0, #4
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_BB
		MOV		R0, #5
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_BD
		MOV		R0, #6
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_BE
		MOV		R0, #11
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_D7
		MOV		R0, #7
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_DB
		MOV		R0, #8
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_DD
		MOV		R0, #9
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_DE
		MOV		R0, #12
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_E7
		MOV		R0, #14
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_EB
		MOV		R0, #0
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_ED
		MOV		R0, #15
		B 		kb_m0404_00_continue
kb_m0404_00_analyze_EE
		MOV		R0, #13
		B 		kb_m0404_00_continue



;==============================================================================
; Fim do Arquivo
;==============================================================================
		ALIGN                        ;Garante que o fim da seção está alinhada 
		END                          ;Fim do arquivo