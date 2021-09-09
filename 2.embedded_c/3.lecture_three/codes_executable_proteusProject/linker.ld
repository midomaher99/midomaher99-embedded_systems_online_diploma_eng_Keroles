
MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128k
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 12k
}
SECTIONS
{
	.text :
	{
		_S_TEXT = .;
		*(.vectors)
		*(.text)
		. = ALIGN(4);
		_E_TEXT = .;
	}>flash
	.rodata :
	{
		_S_RODATA = .;
		*(.rodata)
		. = ALIGN(4);
		_E_RODATA = .;
	}>flash
	.data :
	{
		_S_DATA = .;
		*(.data)
		. = ALIGN(4);
		_E_DATA = .;
	}>sram AT>flash
	.bss :
	{
		_S_BSS = .;
		*(.bss)
		*(COMMON)
		. = ALIGN(4);
		_E_BSS = .;
	}>sram
	
	_stack_top = . + 0x1000;
}
