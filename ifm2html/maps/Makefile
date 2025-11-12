## usage:
##   make ifmfile=mapfile.ifm TARGET
.PHONY: default all
default: map text
all: default raw html dot

ifndef ifm
$(warning Usage: 'make ifm=FILE.ifm TARGET')
$(error 'ifm' not set)
endif

BASENAME = $(basename $(ifm))
SRCFILE = $(BASENAME).ifm
PAPERSIZE = a4

################################################################################
# PRIMARY TARGETS
PS_MAPFILE = $(BASENAME).map.ps
PDF_MAPFILE = $(BASENAME).map.pdf

TEXT_TASKFILE = $(BASENAME).tasks.txt
TEXT_ITEMFILE = $(BASENAME).items.txt

RAW_MAPFILE = $(BASENAME).map.raw
RAW_TASKFILE = $(BASENAME).tasks.raw
RAW_ITEMFILE = $(BASENAME).items.raw

HTML_INDEXFILE = $(BASENAME)-index.html

PS_DOTFILE = $(BASENAME).dot.ps
PDF_DOTFILE = $(BASENAME).dot.pdf

IFMOPTS =
# IFMOPTS = "-S verbose"

.PHONY: map tasks items text dot pdfmap pdfdot rawmap rawtasks rawitems raw

map: $(PS_MAPFILE)
pdfmap: $(PDF_MAPFILE)

tasks: $(TEXT_TASKFILE)
items: $(TEXT_ITEMFILE)
text:  $(TEXT_TASKFILE) $(TEXT_ITEMFILE)

rawmap: $(RAW_MAPFILE)
rawtasks: $(RAW_TASKFILE)
rawitems: $(RAW_ITEMFILE)
raw: $(RAW_ITEMFILE) $(RAW_TASKFILE) $(RAW_MAPFILE)

html: $(HTML_INDEXFILE)

dot: $(PS_DOTFILE)
pdfdot: $(PDF_DOTFILE)

%.tasks.txt: %.ifm
	@$(REPORT)
	ifm $(IFMOPTS) -t -f text -o $@ $<

%.items.txt: %.ifm
	@$(REPORT)
	ifm $(IFMOPTS) -i -f text -o $@ $<

%.map.raw: %.ifm
	@$(REPORT)
	ifm $(IFMOPTS) -m -f raw -o $@ $<
%.tasks.raw: %.ifm
	@$(REPORT)
	ifm $(IFMOPTS) -t -f raw -o $@ $<
%.items.raw: %.ifm
	@$(REPORT)
	ifm $(IFMOPTS) -i -f raw -o $@ $<

%-index.html: %.ifm
	@$(REPORT)
	ifm2html $<

%.map.ps: %.ifm
	@$(REPORT)
	ifm $(IFMOPTS) -m -f ps -o $@ $<

%.dot.dot: %.ifm
	@$(REPORT)
	ifm $(IFMOPTS) -t -f dot -o $@ $<

%.ps: %.dot
	@$(REPORT)
	dot -Tps -o $@ $<

%.pdf: %.ps
	@$(REPORT)
	ps2pdf -sPAPERSIZE=$(PAPERSIZE) $< $@


################################################################################
# CLEANUP
.PHONY: clean
clean:
	@rm -fv $(PDF_MAPFILE) $(PS_MAPFILE)
	@rm -fv $(TEXT_TASKFILE) $(TEXT_ITEMFILE)
	@rm -fv $(RAW_TASKFILE) $(RAW_ITEMFILE) $(RAW_MAPFILE)
	@rm -fv $(PS_DOTFILE) $(PDF_DOTFILE)

################################################################################
.PHONY: help
help:
	@echo
	@echo "TARGETS"
	@echo "   map"
	@echo "   tasks"
	@echo "   items"
	@echo "   html"
	@echo "   raw"
	@echo "   dot"
	@echo "   clean"
	@echo

## a handy macro
REPORT=echo -e '\n\n======== Making $@ ========\n'

