----------------------------------------------------------------------------------
-- Engineer: Juan Garcia Villagran
-- Create Date:    11:44:14 12/16/2019 
-- Design Name: 
-- Module Name:    P6 - Behavioral 
-- Project Name:   Practica 6
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use ieee.std_logic_unsigned.all;

entity P6 is
    Port ( S 	: in  	STD_LOGIC_VECTOR (2 downto 0);
           A 	: in  	STD_LOGIC_VECTOR (3 downto 0);
           B 	: in 	 	STD_LOGIC_VECTOR (3 downto 0);
           Ci 	: in  	STD_LOGIC;
           Co 	: out  	STD_LOGIC;
           F 	: out  	STD_LOGIC_VECTOR (4 downto 0)
			 );
end P6;

architecture Behavioral of P6 is

	signal alu: STD_LOGIC_VECTOR (4 downto 0) := (others => '0');
begin

with S select
	alu <=		('0' &A) + B 		when "000",
					('0' &A) - B		when "001",
					('0' &A) + 1 		when "010",
					('0' &A) - 1 		when "011",
					A nand B 			when "100",
					A and B 				when "101",
					A xor B 				when "110",
					not A when others;
	Co <= alu(4);
	F <= alu (4 downto 0);
end Behavioral;

