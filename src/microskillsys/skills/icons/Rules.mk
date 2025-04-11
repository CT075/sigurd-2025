sp := $(sp).x
dirstack_$(sp) := $(d)
d := $(dir)

ICONS_$(d) = $(shell find $(d) -type f -name '*.png')

$(d)/installer.event: $(MAKE_ICON_INSTALLER) $(TILEMAGE) $(ICONS_$(d))
	python $(MAKE_ICON_INSTALLER) $(shell dirname $@) --tilemage $(TILEMAGE) \
		--output $@

EVENTS_$(d) := $(d)/main.event $(d)/installer.event

EVENTS := $(EVENTS) $(EVENTS_$(d))

d := $(dirstack_$(sp))
sp := $(basename $(sp))
