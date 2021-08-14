----------------------------------------------------------------------------------
-- Company: Universidad de Huelva
-- Engineer: Juan Garcia Villagran
-- 
-- Create Date:    18:10:55 12/02/2019 
-- Design Name: 
-- Module Name:    Practica5 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
-- N when else, A with select, C if else, E case is
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Practica5 is
    Port ( D3 : in  STD_LOGIC;
           D2 : in  STD_LOGIC;
           D1 : in  STD_LOGIC;
           D0 : in  STD_LOGIC;
           N : out  STD_LOGIC;
           A : out  STD_LOGIC;
           C : out  STD_LOGIC;
           E : out  STD_LOGIC);
end Practica5;

architecture Behavioral of Practica5 is
	Signal Entrada: STD_LOGIC_VECTOR(3 downto 0);
begin
	Entrada <= D3&D2&D1&D0;
	N<=	'1' when Entrada = "0000" else
			'1' when Entrada = "0001" else
			'1' when Entrada = "0010" else
			'1' when Entrada = "0011" else
			'1' when Entrada = "0100" else
			'1' when Entrada = "0101" else
			'1' when Entrada = "0110" else
			'1' when Entrada = "0111" else
			'1' when Entrada = "1000" else
			'1' when Entrada = "1001" else
			'0';
			
	with Entrada select 
	A<= 	 '1' when "0000",
		    '1' when "0001",
			 '1' when "0010",
			 '1' when "0011",
			 '1' when "0100",
			 '1' when "1011",
			 '1' when "1100",
			 '1' when "1101",
			 '1' when "1110",
			 '1' when "1111",
			 '0' when others;
			
	process (Entrada)
	begin
		if 	Entrada="0000" then C<='1';
		elsif Entrada="0001" then C<='1';
		elsif Entrada="0010" then C<='1';
		elsif Entrada="0011" then C<='1';
		elsif Entrada="0100" then C<='1';
		elsif Entrada="1000" then C<='1';
		elsif Entrada="1001" then C<='1';
		elsif Entrada="1010" then C<='1';
		elsif Entrada="1011" then C<='1';
		elsif Entrada="1100" then C<='1';
		else  C<= '0'; 
		end if;
	end process;

	process (Entrada)
		begin
			case Entrada is
			when "0011" => E <= '1';
			when "0100" => E <= '1';
			when "0101" => E <= '1';
			when "0110" => E <= '1';
			when "0111" => E <= '1';
			when "1000" => E <= '1';
			when "1001" => E <= '1';
			when "1010" => E <= '1';
			when "1011" => E <= '1';
			when "1100" => E <= '1';
			when others => E <= '0';
			end case;
	end process;

end Behavioral;

