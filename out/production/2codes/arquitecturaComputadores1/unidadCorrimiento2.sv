module shifterUnit2 (
    input logic [1:0]h, input logic[3:0]f, input logic ir, il,
    output logic [3:0]s
);
    always_comb
        begin
            case(h)
                2'b00: s = f;
                2'b01:begin
                            s = f << 1;
                            s[0] = il;
                        end
                2'b10:begin
                            s = function >> 1;
                            s[3] = ir;
                        end
                2'b11: s = 4'b0000;
            endcase
        end
endmodule
