--------------------------------------------------------------------------------
-- Company: Universidad de Huelva
-- Engineer: Juan Garcia Villagran
--
-- Create Date:   18:12:43 12/16/2019 
-- Project Name:  Practica6
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY P6_TestBench IS
END P6_TestBench;
 
ARCHITECTURE behavior OF P6_TestBench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT P6
    PORT(
         S : IN  std_logic_vector(2 downto 0);
         A : IN  std_logic_vector(3 downto 0);
         B : IN  std_logic_vector(3 downto 0);
         Ci : IN  std_logic;
         Co : OUT  std_logic;
         F : out  STD_LOGIC_VECTOR (4 downto 0)

        );
    END COMPONENT;
    

   --Inputs
   signal S : std_logic_vector(2 downto 0) := (others => '0');
   signal A : std_logic_vector(3 downto 0) := (others => '0');
   signal B : std_logic_vector(3 downto 0) := (others => '0');
   signal Ci : std_logic := '0';

 	--Outputs
   signal Co : std_logic;
   signal F : std_logic_vector(4 downto 0) := (others => '0');
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: P6 PORT MAP (
          S => S,
          A => A,
          B => B,
          Ci => Ci,
          Co => Co,
			 F => F
        );

   -- Clock process definitions
--   <clock>_process :process
--   begin
--		<clock> <= '0';
--		wait for <clock>_period/2;
--		<clock> <= '1';
--		wait for <clock>_period/2;
--  end process;
 

  -- Stimulus process
  stim_proc: process
   begin
			wait for 50 ns;
		S<="000"; A<="0110"; B<="0010"; Ci<='1';
			wait for 50 ns;
		S<="000"; A<="0110"; B<="0010"; Ci<='0';
			wait for 50 ns;
		S<="001"; A<="0110"; B<="0010"; Ci<='0';
			wait for 50 ns;
		S<="010"; A<="0110"; B<="0010"; Ci<='1';
			wait for 50 ns;
		S<="010"; A<="0110"; B<="0010"; Ci<='0';
			wait for 50 ns;
		S<="011"; A<="0110"; B<="0010"; Ci<='0';
			wait for 50 ns;
		S<="100"; A<="0110"; B<="0010"; Ci<='0';
			wait for 50 ns;
		S<="001"; A<="0110"; B<="0010"; Ci<='0';
			wait for 50 ns;
		S<="110"; A<="0110"; B<="0010"; Ci<='0';
			wait for 50 ns;
		S<="111"; A<="0110"; B<="0010"; Ci<='0';
			wait for 50 ns;

      wait;
   end process;

END;
