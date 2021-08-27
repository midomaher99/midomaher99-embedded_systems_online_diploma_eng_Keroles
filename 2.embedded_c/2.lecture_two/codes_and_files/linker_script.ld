ENTRY(reset)
MEMORY
{
	mem (rwx) : ORIGIN = 0x0, LENGTH = 64M
}

SECTIONS
{
	. = 0x10000;
	.reset . :
	{
		startup.o(.text)
	}>mem
	.texet :
	{
		*(.text)
	}>mem
	.data :
	{
		*(.data)
	}>mem
	. = . + 0x1000;
	stack_top = .;
}