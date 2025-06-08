# Build tools in bin/
# These can be called recursively because those tools are all self-contained

VENDOR_BIN := $(VENDOR_DIR)/bin

LYN_DIR := $(VENDOR_BIN)/lyn
LYN := $(LYN_DIR)/lyn

# ColorzCore needs to be run from the directory containing the `Language Raws`
# folder (it doesn't handle the `-raws` flag properly), so we simply copy
# everything into the root of the build dir.
COLORZCORE_DIR := $(VENDOR_BIN)/ColorzCore/ColorzCore
COLORZCORE := $(BUILD_DIR)/ColorzCore$(EXE)
EA_STD_LIB_DIR := $(VENDOR_DIR)/EAStandardLibrary

$(LYN_DIR)/Makefile:
	cd $(LYN_DIR) && cmake .

$(LYN): $(LYN_DIR)/Makefile
	cd $(LYN_DIR) && $(MAKE)

PARSEFILE_DIR := $(VENDOR_BIN)/ParseFile
PARSEFILE := $(BUILD_DIR)/ParseFile

$(PARSEFILE): $(PARSEFILE_DIR)/ParseFile.hs $(PARSEFILE_DIR)/FlagUtilities.hs \
		$(PARSEFILE_DIR)/GBAUtilities.hs $(PARSEFILE_DIR)/FEParser.hs
	ghc $< -i$(PARSEFILE_DIR) -o $@

TMX2EA := $(BIN_DIR)/tmx2ea.py

FORMATTING_DIR := $(BIN_DIR)/cam-formatting-suite

TILEMAGE := $(FORMATTING_DIR)/target/release/tilemage-bin
MAR2DMP := $(FORMATTING_DIR)/target/release/mar2dmp
STRUCT_MUNGER := $(FORMATTING_DIR)/target/release/struct_munger
FEMAPTOOL := $(FORMATTING_DIR)/target/release/femaptool

FORMATTING_TOOLS := $(MAR2DMP) $(STRUCT_MUNGER) $(TILEMAGE)

.PHONY: $(FORMATTING_TOOLS)

$(FORMATTING_TOOLS) &:
	cd $(FORMATTING_DIR) && cargo build --profile release

TEXT_PROCESS_CLASSIC := $(VENDOR_BIN)/text-process-classic.py

MAKE_ICON_INSTALLER := $(BIN_DIR)/make_icon_installer.py

$(COLORZCORE):
	dotnet publish -o $(BUILD_DIR) $(COLORZCORE_DIR)/ColorzCore.csproj

.PHONY: tools
tools: $(LYN) $(COLORZCORE)

.PHONY: clean-tools
clean-tools:
	cd $(BIN_DIR)/lyn && make clean
	cd $(BIN_DIR)/ParseFile && rm -rf *.o
