
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity P7 is
    Port ( E, CK, RS : in  STD_LOGIC;
           S, Q2, Q1, Q0 : out  STD_LOGIC);
end P7;

architecture Behavioral of P7 is

	subtype mis_estados is std_logic_vector (2 downto 0);
	constant A 		: mis_estados := "000";
	constant B 		: mis_estados := "001";
	constant C 		: mis_estados := "010";
	constant D 		: mis_estados := "011";
	constant E_e 	: mis_estados := "100";
	constant F 		: mis_estados := "101";
	constant G 		: mis_estados := "110";
	
	signal 	estado 	: mis_estados;
begin
	EVOLUCION:process
	begin
		wait until CK ='1';
		if (RS = '1') then estado <= A;
		else case estado is
			when A 		=> if (E = '0') then estado <= B; 	else estado <= E_e; end if;
			when B 		=> if (E = '0') then estado <= B; 	else estado <= C; end if;
			when C 		=> if (E = '0') then estado <= D; 	else estado <= E_e; end if;
			when D 		=> if (E = '0') then estado <= D; 	else estado <= A; end if;
			when E_e 	=> if (E = '0') then estado <= F; 	else estado <= E_e; end if;
			when F 		=> if (E = '0') then estado <= B; 	else estado <= G; end if;
			when G 		=> if (E = '0') then estado <= A; 	else estado <= G; end if;

			when others =>
			end case;
		end if;
	end process;

	S <= '1' when estado = G or estado = D else '0';
	
	
end Behavioral;

