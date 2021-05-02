-- processador_com_acelerador_tb.vhd

-- Generated using ACDS version 20.1 720

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity processador_com_acelerador_tb is
end entity processador_com_acelerador_tb;

architecture rtl of processador_com_acelerador_tb is
	component processador_com_acelerador is
		port (
			clk_clk       : in std_logic := 'X'; -- clk
			reset_reset_n : in std_logic := 'X'  -- reset_n
		);
	end component processador_com_acelerador;

	component altera_avalon_clock_source is
		generic (
			CLOCK_RATE : positive := 10;
			CLOCK_UNIT : positive := 1000000
		);
		port (
			clk : out std_logic   -- clk
		);
	end component altera_avalon_clock_source;

	component altera_avalon_reset_source is
		generic (
			ASSERT_HIGH_RESET    : integer := 1;
			INITIAL_RESET_CYCLES : integer := 0
		);
		port (
			reset : out std_logic;        -- reset_n
			clk   : in  std_logic := 'X'  -- clk
		);
	end component altera_avalon_reset_source;

	signal processador_com_acelerador_inst_clk_bfm_clk_clk       : std_logic; -- processador_com_acelerador_inst_clk_bfm:clk -> [processador_com_acelerador_inst:clk_clk, processador_com_acelerador_inst_reset_bfm:clk]
	signal processador_com_acelerador_inst_reset_bfm_reset_reset : std_logic; -- processador_com_acelerador_inst_reset_bfm:reset -> processador_com_acelerador_inst:reset_reset_n

begin

	processador_com_acelerador_inst : component processador_com_acelerador
		port map (
			clk_clk       => processador_com_acelerador_inst_clk_bfm_clk_clk,       --   clk.clk
			reset_reset_n => processador_com_acelerador_inst_reset_bfm_reset_reset  -- reset.reset_n
		);

	processador_com_acelerador_inst_clk_bfm : component altera_avalon_clock_source
		generic map (
			CLOCK_RATE => 50000000,
			CLOCK_UNIT => 1
		)
		port map (
			clk => processador_com_acelerador_inst_clk_bfm_clk_clk  -- clk.clk
		);

	processador_com_acelerador_inst_reset_bfm : component altera_avalon_reset_source
		generic map (
			ASSERT_HIGH_RESET    => 0,
			INITIAL_RESET_CYCLES => 50
		)
		port map (
			reset => processador_com_acelerador_inst_reset_bfm_reset_reset, -- reset.reset_n
			clk   => processador_com_acelerador_inst_clk_bfm_clk_clk        --   clk.clk
		);

end architecture rtl; -- of processador_com_acelerador_tb