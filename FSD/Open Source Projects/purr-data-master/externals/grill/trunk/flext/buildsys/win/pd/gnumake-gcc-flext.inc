ifdef SHARED
EXT=dll
else
EXT=a
endif

LDFLAGS += -shared

VERNAME=$(OUTNAME).$(FLEXTMAJOR).$(FLEXTMINOR).$(FLEXTMICRO).$(EXT)
TARGET=$(TARGETPATH)/$(VERNAME)
INSTTARGET=$(TARGET)
