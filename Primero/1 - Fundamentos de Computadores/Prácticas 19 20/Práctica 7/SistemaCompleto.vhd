library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Practica7 is
	Port(	E, Reset, CLK_50MHZ, CLK_CR:in STD_LOGIC;
			S:out STD_LOGIC;
			Q2, Q1, Q0 : out  STD_LOGIC);
end Practica7 ;

architecture Behavioral of Practica7 is
	signal CLK_SR : std_logic;
	
	component Antirrebotes
		PORT (CLK_50MHZ, E: IN STD_LOGIC; S: OUT STD_LOGIC);
	end component;
	component P7
		Port(E, RS, CK:in STD_LOGIC;S:out STD_LOGIC; Q2, Q1, Q0 : out  STD_LOGIC);
	end component;
begin
	AR: Antirrebotes PORT MAP (
		E => CLK_CR,
		S => CLK_SR,
		CLK_50MHZ => CLK_50MHZ
	);
	circuito: P7 PORT MAP (
		E => E,
		RS => Reset,
		CK => CLK_SR,
		S => S,
		Q2 => Q2,
		Q1 => Q1,
		Q0 => Q0
	);


end Behavioral;