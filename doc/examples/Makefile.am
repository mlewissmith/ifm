## Automake template for ruins demo.

IFM = $(top_builddir)/src/ifm -I $(top_srcdir)/lib

TXTFILES = ruins-items.txt ruins-tasks.txt ruins-rec.txt

all-local: ifm $(TXTFILES)

ifm:; @ cd $(top_builddir)/src; $(MAKE) -s

%-rec.txt: %.ifm
	$(IFM) -t -f rec -o $@ $<

%-items.txt: %.ifm
	$(IFM) -i -o $@ $<

%-tasks.txt: %.ifm
	$(IFM) -t -o $@ $<

EXTRA_DIST = $(TXTFILES)
