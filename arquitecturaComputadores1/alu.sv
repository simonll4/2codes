module alu #(parameter N = 4)
				(input logic [N-1:0] a,b,
				 input logic [3:0] select,
				 output logic [N-1:0] result, output logic z,s,v,c);
				 
logic Cout;

always_comb
	case(select)
	
		4'b0000: {Cout,result} = a;						//trasnferencia de a
		4'b0001: {Cout,result} = a + 4'b1;				//incremento de a
		4'b0010: {Cout,result} = a + b;					//adicion
		4'b0011: {Cout,result} = a + b + 4'b1;			//adicion con acarreo
		4'b0100: {Cout,result} = a + ~(b);				//a mas complemeento a1 de b
		4'b0101: {Cout,result} = a + ~(b) + 4'b1 ;   // sustraccion(a - b) complneto a1 + 1
		4'b0110: {Cout,result} = a - 4'b1;				//decremento de a
		4'b0111: {Cout,result} = a;						//trasnferencia
		4'b1000: {Cout,result} = a & b;					//AND
		4'b1010: {Cout,result} = a | b;  					//OR
		4'b1100:	{Cout,result} = a ^ b; 					//XOR
		4'b1110: {Cout,result} = ~a; 						//complemento a
		default: {Cout,result} = a;
		
	endcase
	
assign c = Cout;
assign v = ((a[N-1] & b[N-1] & ~result[N-1]) | (~a[N-1] & ~b[N-1] & result[N-1])) & 
				(select[N-1] == 1'b0); //[overflow] operandos con mismo signo y select[3] en 0
assign z = (result == 4'b0000); 			// z=0 si la salida es distinta de cero
assign s = result[N-1];			// valor del bit mas significativo de la salida

endmodule
