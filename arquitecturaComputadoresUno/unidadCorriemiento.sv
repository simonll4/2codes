module unidadCorrimiento(input logic [1:0] select,
			input logic Ir,Il,
			input logic [3:0] data,
			output logic [3:0] exit,
			output logic serialOutput1,serialOutput2);
			
		
	always_comb
		case(select)
		
		2'b00: 	exit = data;
		2'b01: 	exit = {data[2:0],Ir};//corriemiento a la izquierda  {f[2], f[1], f[0], Ir};
		2'b10:	exit = {Il,data[3:1]}; //corrimiento a la derecha {i_right, f[3], f[2], f[1]};
		2'b11:	exit =  4'b0000;   //tranferencia de ceros
		default: exit = data;
		endcase
		
assign serialOutput1 = data[3];
assign serialOutput2	= data[0];
			
endmodule