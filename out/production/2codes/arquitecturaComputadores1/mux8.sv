module mux8
  #(parameter N=4)
  (input logic [N-1:0] d0, d1, d2, d3, 
                           d4, d5, d6, d7,
  input logic [2:0] select, 
  output logic [N-1:0] exit);
  
  always_comb
  case(select)
    3'b000: exit = d0;
    3'b001: exit = d1;
    3'b010: exit = d2;
    3'b011: exit = d3;
    3'b100: exit = d4;
    3'b101: exit = d5;
    3'b110: exit = d6;
    3'b111: exit = d7;
  endcase
  
endmodule