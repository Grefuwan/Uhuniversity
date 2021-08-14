--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   23:57:35 12/03/2019
-- Design Name:   
-- Module Name:   C:/Users/Grefuwan/Documents/Universidad/UHU/1/1 - Fundamentos de Computadores/Practicas/P5/Practica5/P5_TestBench.vhd
-- Project Name:  Practica5
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Practica5
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY P5_TestBench IS
END P5_TestBench;
 
ARCHITECTURE behavior OF P5_TestBench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Practica5
    PORT(
         D3 : IN  std_logic;
         D2 : IN  std_logic;
         D1 : IN  std_logic;
         D0 : IN  std_logic;
         N : OUT  std_logic;
         A : OUT  std_logic;
         C : OUT  std_logic;
         E : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal D3 : std_logic := '0';
   signal D2 : std_logic := '0';
   signal D1 : std_logic := '0';
   signal D0 : std_logic := '0';

 	--Outputs
   signal N : std_logic;
   signal A : std_logic;
   signal C : std_logic;
   signal E : std_logic;

	Signal Entrada: STD_LOGIC_VECTOR(3 downto 0);
	Signal Entrada_int: INTEGER range 0 to 15;
 
BEGIN
		Entrada <= D3&D2&D1&D0;

	-- Instantiate the Unit Under Test (UUT)
   uut: Practica5 PORT MAP (
          D3 => D3,
          D2 => D2,
          D1 => D1,
          D0 => D0,
          N => N,
          A => A,
          C => C,
          E => E
        );

   -- Clock process definitions
--   <clock>_process :process
--   begin
--		<clock> <= '0';
--		wait for <clock>_period/2;
--		<clock> <= '1';
--		wait for <clock>_period/2;
--   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		D3 <= '0';D2 <= '0';D1 <= '0';D0 <= '0';
		Wait for 50 ns;
		D3 <= '0';D2 <= '0';D1 <= '0';D0 <= '1';
		Wait for 50 ns;
		D3 <= '0';D2 <= '0';D1 <= '1';D0 <= '0';
		Wait for 50 ns;
		D3 <= '0';D2 <= '0';D1 <= '1';D0 <= '1';
		Wait for 50 ns;
		D3 <= '0';D2 <= '1';D1 <= '0';D0 <= '0';
		Wait for 50 ns;
		D3 <= '0';D2 <= '1';D1 <= '0';D0 <= '1';
		Wait for 50 ns;
		D3 <= '0';D2 <= '1';D1 <= '1';D0 <= '0';
		Wait for 50 ns;
		D3 <= '0';D2 <= '1';D1 <= '1';D0 <= '1';
		Wait for 50 ns;
		D3 <= '1';D2 <= '0';D1 <= '0';D0 <= '0';
		Wait for 50 ns;
		D3 <= '1';D2 <= '0';D1 <= '0';D0 <= '1';
		Wait for 50 ns;
		D3 <= '1';D2 <= '0';D1 <= '1';D0 <= '0';
		Wait for 50 ns;
		D3 <= '1';D2 <= '0';D1 <= '1';D0 <= '1';
		Wait for 50 ns;
		D3 <= '1';D2 <= '1';D1 <= '0';D0 <= '0';
		Wait for 50 ns;
		D3 <= '1';D2 <= '1';D1 <= '0';D0 <= '1';
		Wait for 50 ns;
		D3 <= '1';D2 <= '1';D1 <= '1';D0 <= '0';
		Wait for 50 ns;
		D3 <= '1';D2 <= '1';D1 <= '1';D0 <= '1';
		Wait for 50 ns;

      wait;
   end process;

END;
