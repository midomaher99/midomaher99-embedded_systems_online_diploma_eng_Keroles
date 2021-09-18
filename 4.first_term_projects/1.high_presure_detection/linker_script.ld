MEMORY
{
	flash (RX) : ORIGIN = 0x08000000, LENGTH = 128k
	SRAM (RWX) : ORIGIN = 0x20000000, LENGTH = 12k
}
SECTIONS
{
	._reset :
	{
		_S_RESET = .;
		*(.vectors)
		. = ALIGN(4);
		_E_RESET = .;
	}>flash
	.text :
	{
		_S_TEXT = .;
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
	}>SRAM AT> flash
	.bss :
	{
		_S_BSS = .;
		*(.bss)
		. = ALIGN(4);
		_E_BSS = .;
	}>SRAM
	_stack_top = . + 0x1000;
}