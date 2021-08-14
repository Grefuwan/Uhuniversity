
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY P7TB_final IS
END P7TB_final;
 
ARCHITECTURE behavior OF P7TB_final IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Practica7
    PORT(
         E : IN  std_logic;
         Reset : IN  std_logic;
         CLK_50MHZ : IN  std_logic;
         CLK_CR : IN  std_logic;
         S : OUT  std_logic;
         Q2 : OUT  std_logic;
         Q1 : OUT  std_logic;
         Q0 : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal E 			: std_logic := '0';
   signal Reset 		: std_logic := '0';
   signal CLK_50MHZ 	: std_logic := '0';
   signal CLK_CR 		: std_logic := '0';

 	--Outputs
   signal S 	: std_logic;
   signal Q2 	: std_logic;
   signal Q1 	: std_logic;
   signal Q0 	: std_logic;

   -- Clock period definitions
   constant CLK_50MHZ_period 	: time := 10 ns;
   constant CLK_CR_period 		: time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Practica7 PORT MAP (
          E 			=> E,
          Reset		=> Reset,
          CLK_50MHZ 	=> CLK_50MHZ,
          CLK_CR 		=> CLK_CR,
          S 			=> S,
          Q2 			=> Q2,
          Q1 			=> Q1,
          Q0 			=> Q0
        );

   -- Clock process definitions
   CLK_50MHZ_process :process
   begin
		CLK_50MHZ <= '0';
		wait for CLK_50MHZ_period/2;
		CLK_50MHZ <= '1';
		wait for CLK_50MHZ_period/2;
   end process;
 
   CLK_CR_process :process
   begin
		CLK_CR <= '0';
		wait for CLK_CR_period/2;
		CLK_CR <= '1';
		wait for CLK_CR_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for CLK_50MHZ_period*10;

      -- insert stimulus here 
wait for CLK_CR_period*10; -- Ejecutar durante 5 us

      -- Reseteo
		E<='0';Reset<='0';	Wait for 100 ns;
		E<='0';Reset<='1';	Wait for 100 ns;
		E<='0';Reset<='0';	Wait for 100 ns;
		
		-- Llegar hasta L1
		E<='0';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='0';CLK_50MHZ<='1';	Wait for 100 ns; -- L1
		E<='1';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='1';CLK_50MHZ<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='0';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='0';CLK_50MHZ<='1';	Wait for 100 ns; -- L1
		E<='0';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='0';CLK_50MHZ<='1';	Wait for 100 ns; -- L2
		E<='1';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='1';CLK_50MHZ<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='0';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='0';CLK_50MHZ<='1';	Wait for 100 ns; -- L1
		E<='0';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='0';CLK_50MHZ<='1';	Wait for 100 ns; -- L2
		E<='0';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='0';CLK_50MHZ<='1';	Wait for 100 ns; -- LF y S
		E<='1';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='1';CLK_50MHZ<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='1';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='1';CLK_50MHZ<='1';	Wait for 100 ns; -- H1
		E<='0';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='0';CLK_50MHZ<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='1';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='1';CLK_50MHZ<='1';	Wait for 100 ns; -- H1
		E<='1';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='1';CLK_50MHZ<='1';	Wait for 100 ns; -- H2
		E<='0';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='0';CLK_50MHZ<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='1';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='1';CLK_50MHZ<='1';	Wait for 100 ns; -- H1
		E<='1';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='1';CLK_50MHZ<='1';	Wait for 100 ns; -- H2
		E<='1';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='1';CLK_50MHZ<='1';	Wait for 100 ns; -- HF y S
		E<='0';CLK_50MHZ<='0';	Wait for 100 ns;
		E<='0';CLK_50MHZ<='1';	Wait for 100 ns; -- RESET
      wait;
   end process;

END;
