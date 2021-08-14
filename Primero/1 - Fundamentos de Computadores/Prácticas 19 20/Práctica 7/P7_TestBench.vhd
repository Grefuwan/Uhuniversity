
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY P7_TestBench IS
END P7_TestBench;
 
ARCHITECTURE behavior OF P7_TestBench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT P7
    PORT(
         E 	: IN  std_logic;
         CK : IN  std_logic;
         RS : IN  std_logic;
         S : OUT  std_logic;
			Q2: OUT  std_logic;
			Q1: OUT  std_logic;
			Q0: OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal E 	: std_logic := '0';
   signal CK 	: std_logic := '0';
   signal RS 	: std_logic := '0';

 	--Outputs
   signal S : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant CK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: P7 PORT MAP (
          E 	=> E,
          CK 	=> CK,
          RS 	=> RS,
          S => S
        );

   -- Clock process definitions
   CK_process :process
   begin
		CK <= '0';
		wait for CK_period/2;
		CK <= '1';
		wait for CK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for CK_period*10;

      -- insert stimulus here 

      wait for CK_period*10; -- Ejecutar durante 5 us

      -- Reseteo
		E<='0';RS<='0';	Wait for 100 ns;
		E<='0';RS<='1';	Wait for 100 ns;
		E<='0';RS<='0';	Wait for 100 ns;
		
		-- Llegar hasta L1
		E<='0';CK<='0';	Wait for 100 ns;
		E<='0';CK<='1';	Wait for 100 ns; -- L1
		E<='1';CK<='0';	Wait for 100 ns;
		E<='1';CK<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='0';CK<='0';	Wait for 100 ns;
		E<='0';CK<='1';	Wait for 100 ns; -- L1
		E<='0';CK<='0';	Wait for 100 ns;
		E<='0';CK<='1';	Wait for 100 ns; -- L2
		E<='1';CK<='0';	Wait for 100 ns;
		E<='1';CK<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='0';CK<='0';	Wait for 100 ns;
		E<='0';CK<='1';	Wait for 100 ns; -- L1
		E<='0';CK<='0';	Wait for 100 ns;
		E<='0';CK<='1';	Wait for 100 ns; -- L2
		E<='0';CK<='0';	Wait for 100 ns;
		E<='0';CK<='1';	Wait for 100 ns; -- LF y S
		E<='1';CK<='0';	Wait for 100 ns;
		E<='1';CK<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='1';CK<='0';	Wait for 100 ns;
		E<='1';CK<='1';	Wait for 100 ns; -- H1
		E<='0';CK<='0';	Wait for 100 ns;
		E<='0';CK<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='1';CK<='0';	Wait for 100 ns;
		E<='1';CK<='1';	Wait for 100 ns; -- H1
		E<='1';CK<='0';	Wait for 100 ns;
		E<='1';CK<='1';	Wait for 100 ns; -- H2
		E<='0';CK<='0';	Wait for 100 ns;
		E<='0';CK<='1';	Wait for 100 ns; -- RESET
		
		-- Llegar hasta L1
		E<='1';CK<='0';	Wait for 100 ns;
		E<='1';CK<='1';	Wait for 100 ns; -- H1
		E<='1';CK<='0';	Wait for 100 ns;
		E<='1';CK<='1';	Wait for 100 ns; -- H2
		E<='1';CK<='0';	Wait for 100 ns;
		E<='1';CK<='1';	Wait for 100 ns; -- HF y S
		E<='0';CK<='0';	Wait for 100 ns;
		E<='0';CK<='1';	Wait for 100 ns; -- RESET
      wait;
   end process;

END;
