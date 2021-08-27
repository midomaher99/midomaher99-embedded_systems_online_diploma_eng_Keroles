.global reset

reset :
	ldr sp, =stack_top
	bl main
	b stop
stop : 
	b stop