transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -sv -work work +incdir+C:/Users/Usuario/Desktop/2codes/arquitecturaComputadores1/proyectoArqui {C:/Users/Usuario/Desktop/2codes/arquitecturaComputadores1/proyectoArqui/reducedVersionARM.sv}

