
MBOOT_HEADER_MAGIC  equ     0x1BADB002
MBOOT_PAGE_ALIGN    equ     1 << 0
MBOOT_MEM_INFO      equ     1 << 1    
MBOOT_HEADER_FLAGS  equ     MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO
MBOOT_CHECKSUM      equ     -(MBOOT_HEADER_MAGIC+MBOOT_HEADER_FLAGS)

; 符合Multiboot规范的 OS 映象需要这样一个 magic Multiboot 头
; Multiboot 头的分布必须如下表所示：
; ----------------------------------------------------------
; 偏移量  类型  域名        备注
;
;   0     u32   magic       必需
;   4     u32   flags       必需 
;   8     u32   checksum    必需 
;
; 我们只使用到这些就够了，更多的详细说明请参阅 GNU 相关文档
;-----------------------------------------------------------

;-----------------------------------------------------------------------------

[BITS 32]   ; 所有代码以 32-bit 的方式编译
section .text   ; 代码段从这里开始

dd MBOOT_HEADER_MAGIC   ; GRUB 会通过这个魔数判断该映像是否支持
dd MBOOT_HEADER_FLAGS   ; GRUB 的一些加载时选项，其详细注释在定义处
dd MBOOT_CHECKSUM       ; 检测数值，其含义在定义处

[GLOBAL start]      ; 向外部声明内核代码入口，此处提供该声明给链接器
[GLOBAL glb_mboot_ptr]  ; 向外部声明 struct multiboot * 变量
[EXTERN kern_entry]     ; 声明内核 C 代码的入口函数

start:
	cli
	mov esp,STACK_TOP
	mov ebp,0
	and esp,0fffffff0h
	mov [glb_mboot_ptr],ebx
	call kern_entry
stop:
	hlt
	jmp stop

section .bss
stack:
	resb 32768
glb_mboot_ptr:
	resb 4

STACK_TOP equ $-stack-1
