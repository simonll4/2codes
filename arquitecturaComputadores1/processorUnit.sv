
//unidad de procesamiento

module processorUnit(input logic [2:0] A,B,D,H
							input logic [3:0] F,
							input logic [3:0] inData,
							output logic [3:0] outData);
	
		


endmodule


//banco de registros(seleccion de buses-salidas, seleccion de escritura-entrada)

module ram3port #(parameter N = 2, M = 4)
                 (input logic clk,
                  input logic [N-1:0] a1, a2, a3,
						input logic [M-1:0] d3,
                  output logic [M-1:0] d1, d2
                  );
						
  
  logic [M-1:0] mem[2**N-1:0];	//3 bit
  
  always @(posedge clk)
     mem[a3] <= d3;

  assign d1 = mem[a1];
  assign d2 = mem[a2];
endmodule


//unidad aritmetica y logica

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

//unidad de corrimiento
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
