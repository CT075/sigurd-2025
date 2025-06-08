#include "global.h"
#include "uimenu.h"
#include "bmmenu.h"

#include "unit_action_menu_lib.h"

extern u16 EirikaTalk;

extern struct SEPUAvailabilityConfig sepuConfig1;

u8 SEPUIsEirika(const struct MenuItemDef *self, int number) {
  return SEPUAvailableImpl(self, number, &sepuConfig1);
}

u8 SEPUHasIronSword(const struct MenuItemDef *self, int number) {
  struct SEPUAvailabilityConfig sepuConfig2 = {
    .character = 0xAA,
    .class = 0xBB,
    .item = 0xCC,
    .flag = 0xDD,
  };
  return SEPUAvailableImpl(self, number, &sepuConfig2);
}

u8 runEirikaTalk(struct MenuProc *owner, struct MenuItemProc *cmd) {
  return runEvent(owner, cmd, &EirikaTalk);
}

const struct MenuItemDef newUnitActionItems[] = {
    {"", 0x67A, 0x6CC, 0, 0x4E, UnitActionMenu_CanSeize, 0, UnitActionMenu_Seize, 0, 0, 0},
    {"", 0x67B, 0x6C0, 0, 0x4F, AttackCommandUsability, 0, UnitActionMenu_Attack, 0, DisplayUnitStandingAttackRange, HideMoveRangeGraphicsWrapper}, 
    {"", 0x67B, 0x6C0, 0, 0x50, AttackBallistaCommandUsability, 0, UnitActionMenu_Attack, 0, DisplayUnitStandingAttackRange, HideMoveRangeGraphicsWrapper}, 
    {"", 0x67C, 0x6C1, 0, 0x51, StaffCommandUsability, 0, StaffCommandEffect, 0, StaffCommandRange, HideMoveRangeGraphicsWrapper2}, 
    {"", 0x391, 0x391, 0, 0,    SEPUIsEirika,         0, runEirikaTalk,     0, 0, 0},
    {"", 0x392, 0x392, 0, 0,    SEPUHasIronSword,     0, runEirikaTalk,     0, 0, 0},
    {"", 0x691, 0x6D6, 4, 0x52, RideCommandUsability, 0, RideCommandEffect, 0, 0, 0},
    {"", 0x692, 0x6D7, 4, 0x53, ExitCommandUsability, 0, ExitCommandEffect, 0, 0, 0},
    {"", 0x67D, 0x6C3, 0, 0x54, PlayCommandUsability, 0, PlayCommandEffect, 0, 0, 0}, 
    {"", 0x67E, 0x6C2, 0, 0x55, DanceCommandUsability, 0, PlayCommandEffect, 0, 0, 0}, 
    {"", 0x67F, 0x6C4, 0, 0x56, StealCommandUsability, 0, StealCommandEffect, 0, 0, 0}, 
    {"", 0x693, 0x6DD, 0, 0x57, SummonCommandUsability, 0, SummonCommandEffect, 0, 0, 0},
    {"", 0x693, 0x6DD, 0, 0x58, YobimaCommandUsability, 0, YobimaCommandEffect, 0, 0, 0},
    {"", 0x694, 0x6DE, 0, 0x59, PickCommandUsability, 0, PickCommandEffect, 0, 0, 0},
    {"", 0x680, 0x6C9, 0, 0x5A, TalkCommandUsability, 0, TalkCommandEffect, 0, 0, 0},
    {"", 0x681, 0x6CA, 0, 0x5B, SupportCommandUsability, 0, SupportCommandEffect, 0, 0, 0},
    {"", 0x682, 0x6CB, 0, 0x5C, VisitCommandUsability, 0, VisitCommandEffect, 0, 0, 0},
    {"", 0x683, 0x6CE, 0, 0x5D, ChestCommandUsability, 0, ChestCommandEffect, 0, 0, 0}, 
    {"", 0x684, 0x6CD, 0, 0x5E, DoorCommandUsability, 0, DoorCommandEffect, 0, 0, 0}, 
    {"", 0x685, 0x6CF, 0, 0x5F, ArmoryCommandUsability, 0, ArmoryCommandEffect, 0, 0, 0}, 
    {"", 0x686, 0x6D0, 0, 0x60, VendorCommandUsability, 0, VendorCommandEffect, 0, 0, 0}, 
    {"", 0x687, 0x6D1, 0, 0x61, SecretShopCommandUsability, 0, SecretShopCommandEffect, 0, 0, 0},
    {"", 0x688, 0x6D2, 0, 0x62, ArenaCommandUsability, 0, ArenaCommandEffect, 0, 0, 0}, 
    {"", 0x689, 0x6C5, 0, 0x63, RescueUsability, 0, RescueEffect, 0, 0, 0}, 
    {"", 0x68A, 0x6C6, 0, 0x64, DropUsability, 0, DropEffect, 0, 0, 0}, 
    {"", 0x68B, 0x6C8, 4, 0x65, TakeUsability, 0, TakeEffect, 0, 0, 0}, 
    {"", 0x68C, 0x6C7, 4, 0x66, GiveUsability, 0, GiveEffect, 0, 0, 0}, 
    {"", 0x68D, 0x6D3, 0, 0x67, ItemCommandUsability, 0, ItemCommandEffect, 0, 0, 0},
    {"", 0x68E, 0x6D4, 4, 0x68, ItemSubMenu_IsTradeAvailable, 0, TradeCommandEffect, 0, 0, 0},
    {"", 0x68F, 0x6D5, 4, 0x69, SupplyUsability, 0, SupplyCommandEffect, 0, 0, 0},
    {"", 0x695, 0x6BF, 0, 0x6B, MenuAlwaysEnabled, 0, EffectWait, 0, 0, 0},
    MenuItemsEnd
};
