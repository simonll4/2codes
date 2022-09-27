module shifterUnit(input logic [2:0] select,
			input logic Ir,Il,
			input logic [3:0] data,
			output logic [3:0] exit,
			output logic serialOutput1,serialOutput2);

		
	always_comb
		case(select)
		
		3'b000: 	exit = data;
		3'b001: 	exit = {data[2:0],Ir};//corriemiento a la izquierda  {f[2], f[1], f[0], Ir};
		3'b010:	exit = {Il,data[3:1]}; //corrimiento a la derecha {i_right, f[3], f[2], function[1]};
		3'b011:	exit =  4'b0000;   //tranferencia de ceros
		3'b101:	exit = {data,data[3]} << 1; //ROL (rotacion a la izquierda)
		3'b110: 	exit = {data[0],data} >>1; //ROR (rotacion a la izquierda)_
		default: exit = data;
		endcase
		
assign serialOutput1 = data[3];
assign serialOutput2	= data[0];
			
endmodule