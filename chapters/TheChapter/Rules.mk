sp := $(sp).x
dirstack_$(sp) := $(d)
d := $(dir)

$(d)/main.event: $(d)/map.dmp

EVENTS_$(d) := $(d)/main.event $(d)/REDAHelpers.event $(d)/map.event
ASSETS_$(d) := $(d)/map.dmp

$(d)/map.event $(d)/map.dmp &: $(d)/map.tmx
	$(FEMAPTOOL) $< -o map.dmp --installer-file map.event

EVENTS := $(EVENTS) $(EVENTS_$(d))
ASSETS := $(ASSETS) $(ASSETS_$(d))

d := $(dirstack_$(sp))
sp := $(basename $(sp))
