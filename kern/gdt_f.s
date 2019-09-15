[GLOBAL gdt_flush]

gdt_flush:
	mov eax, [esp+4]
	lgdt [eax]
	
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	;update ds...
	
	jmp 0x08: .flush
	;update cs
	;after this jmp ds, es, fs, gs and ss will keep 0x10
	;cs will keep 0x08
.flush:
	ret
