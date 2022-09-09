module deco8 (input logic [2:0] select,
					output logic [3:0] data);
					
	always_comb
	
		case(select)
		3'b000: data = 4'b0000;
		3'b001: data =	4'b0001;
		3'b010: data =	4'b0010;
		3'b011: data =	4'b0011;
		3'b100: data =	4'b0100;
		3'b101: data =	4'b0101;
		3'b110: data =	4'b0110;
		3'b111: data =	4'b0100;
		default: data = 4'bxxxx;
		endcase

endmodule
