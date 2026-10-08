# `nathan` keymap — the layout, in full

This is the reference for the personal `nathan` keymap. It replaces the OEM
quick-start guide: everything below reflects what the firmware actually does.
`keymap.c` in this directory is the source of truth; this file explains it.

Built with the `keeb` project's wrapper:

```sh
./bin/make epomaker/epomaker_split65:nathan
```

---

## 1. The layers

A layer is a parallel keymap. You are always on exactly one, and a *layer key*
switches which one while held (or, for `TO()`, makes it the standing default).

| Layer | Name | How you get there |
|---|---|---|
| 0 | `_BL` — base (Windows) | default; nothing held |
| 1 | `_FL` — Fn (Windows) | hold either **spacebar** |
| 2 | `_MBL` — Mac base | press **Fn + `S`** (`TO(_MBL)`) — sticky, survives reboot |
| 3 | `_MFL` — Mac Fn | hold either **spacebar** while on `_MBL` |
| 4 | `_RST` — recovery | hold **Fn + the top-right corner key** — see §5 |

**Fn is on both spacebars.** Tap a spacebar = space; hold it = Fn. Either hand
can engage the layer, which is the whole point of a split keyboard.

`TO(_MBL)` / `TO(_BL)` are *sticky*: they change the default layer and the
choice survives a power cycle (it is stored in EEPROM). The momentary layers
(`_FL`, `_MFL`) release the moment you lift the key.

---

## 2. Base layer — `_BL` (Windows)

```
Esc   1    2    3    4    5       6    7    8    9    0    -    =    Bksp   Mute
Tab   Q    W    E    R    T       Y    U    I    O    P    [    ]    \      Del
Caps  A    S    D    F    G       H    J    K    L    ;    '    Enter       PgUp
Shift Z    X    C    V    B       N    M    ,    .    /         Shift  Up   PgDn
Ctrl  Win  Alt  Space             Space RAlt RCmd RCtrl        Left  Down Right
```

- **Left `Win`** sends `LGUI`; on macOS (the `_MBL` layer) the same positions
  send `LCmd`/`RCmd`.
- **Bottom right, left→right:** right spacebar (tap = space, hold = Fn),
  `RAlt`, `RCmd`, `RCtrl`, `Left`, `Down`, `Right`.
- **Encoder (knob):** base layer = volume down / up.

## 3. Fn layer — `_FL` (Windows)

Hold either spacebar.

```
`      F1   F2   F3   F4   F5      F6   F7   F8   F9   F10  F11  F12  ·     RESET*
RGB⇄   BT1  BT2  BT3  2.4G  ·       ·    ·    ·    ·    ·    Hue- Hue+  ·     Ins
·      A→Mac ·    ·    ·    ·       ·    ·    ·    ·    Sat- Sat+  ·          Home
·      ·    RGB⏻ ·    ·    ·       NKRO ·    ·    ·    BOOT*     ·    B+   End
Flip   GUI⏻ Spd- ·                 BatQ Spd+ ·    ·         NKRO GUI⏻ RGB⏻
```

- **Fn + number row = F1–F12.** This is done **in the firmware**; it does not
  depend on any host-side (e.g. X11) remapping, and works on every OS and in
  the BIOS/console.
- `RESET*` (hold) and `BOOT` are the recovery pair — see §5.
- **`Hue-`/`Hue+`/`Sat-`/`Sat+`/`B+`/`B-`:** RGB matrix adjustments (right side
  of the layer).
- **`Spd-`/`Spd+`:** RGB effect speed (`RGB_SPD`/`RGB_SPI`) — bottom row,
  `Spd-` on the left half (`[5,2]`) and `Spd+` on the right half (`[11,3]`).
- **`BT1`/`BT2`/`BT3`:** pair/switch Bluetooth device 1/2/3. **`2.4G`:** switch
  to the 2.4 GHz dongle. **`RGB⇄` (`RGB_MOD`):** next lighting effect.
- **`BatQ`:** master-only battery query (lights the LED bar on the right half).
- **`Flip`:** swaps the Fn-row and number row (OEM behaviour); left Ctrl lights
  red while it is on.
- **Safe system toggles** (easy to reach, easy to undo): `NKRO` = `NK_TOGG`,
  `GUI⏻` = `GU_TOGG`, `RGB⏻` = `RGB_TOG`. Each appears **twice** on the layer —
  once in the bottom-right cluster (`[11,6]`/`[11,7]`/`[11,8]`) and once on the
  left half (`NK_TOGG` at `[10,0]`, `GU_TOGG` at `[5,1]`, `RGB_TOG` at `[4,2]`).

## 4. Mac layers — `_MBL` / `_MFL`

Reach `_MBL` with **Fn + `S`**. `_MFL` is its Fn layer (hold a spacebar).
They are the Windows layers with the modifier positions made Mac-native:

| Position | `_BL`/`_FL` | `_MBL`/`_MFL` |
|---|---|---|
| Left modifier beside Alt | `Win` (`LGUI`) | `Cmd` (`LGUI`) |
| `Fn + S` / `Fn + A` | switch to Mac (`TO(_MBL)`) | switch back to Windows (`TO(_BL)`) |

The switch sits on a **different key on each layer**: `Fn + S` goes to `_MBL`,
and `Fn + A` returns to `_BL` — `A` and `S` keep typing normally on the layer
they are not switching from.

`LGUI` *is* Command on macOS, so the right-hand modifiers (`RAlt`, `RCmd`,
`RCtrl`) are the same keycodes on both base layers — the meaningful difference
is the `TO()` switch and the layer's labelling, not the right-hand keycodes.

Everything else (F-keys under Fn, RGB, radio, the recovery pair) is identical.

## 5. Recovery island — the two destructive keys

The only two keys that destroy saved state. They are **deliberately separated**
so a fumble cannot hit both, and both require Fn held:

| Combo | Effect | Risky because |
|---|---|---|
| **Fn + top-right corner key, tapped** | nothing (inert) | — |
| **Fn + top-right corner key, held** | `EE_CLR` — **factory reset**: wipes the emulated EEPROM (layer, RGB, overrides) back to defaults | irreversible without re-configuring |
| **Fn + `/` key** (right half, third row down, `QK_BOOT`) | **reboot into the `wb32-dfu` bootloader** (for flashing) | the half stops typing until reflashed; on this board `QK_BOOT` also clears EEPROM |

- **Top-right corner** = the key that is `Mute` on the base layer (matrix
  `[7,8]`).
- **`QK_BOOT`** sits on the right half, third row down, at the base-layer `/`
  position (matrix `[10,4]`), two key-widths left of the `RShift` column and one
  row above the arrow cluster — no single slip reaches the reset key.

The factory reset is **hold-to-arm**: the reset key does nothing on a tap, so
only a deliberate hold resets.

**If a half drops into the bootloader**, flash it, or power-cycle it — it will
come back. Holding `Esc` at plug-in enters DFU on the **left** half only
(bootmagic; see below); `QK_BOOT` above is the in-keymap route for the right
half that avoids opening the case.

Bootmagic is enabled (`BOOTMAGIC_ENABLE = yes` in this keymap's `rules.mk`) with
`bootmagic.matrix` `[1,0]` — the left half's `Esc` position. So holding `Esc`
while plugging in the left half's USB cable enters its `wb32-dfu` bootloader.
The right half has no equivalent: use `QK_BOOT` (above) or the hardware
spacebar-pin short.

## 6. Key overrides

Small behaviours layered on top of ordinary keys:

| Press | Result |
|---|---|
| **Shift + Esc** | `~` (tilde) |
| **GUI/Cmd + Esc** | `` ` `` (grave) |
| **Shift + Backspace** | Delete |

## 7. Encoder (volume knob)

Turn only — **the knob has no push-click**; it is a bare rotary encoder.

| Layer | Clockwise / counter-clockwise |
|---|---|
| `_BL` / `_MBL` (base) | Volume up / down |
| `_FL` / `_MFL` (Fn) | RGB brightness up / down |

## 8. Wireless and power (from the OEM firmware, unchanged)

- **Bluetooth:** `Fn + Q`/`W`/`E` pair or switch device 1/2/3.
- **2.4 GHz:** `Fn + R` selects the dongle; toggle the side switch to the right.
- **Battery LED:** red blink = low; solid = fully charged (right-half indicator).
- **Battery check:** hold `Fn` and press the `BatQ` key — the left side of the
  bottom row on the right half (matrix `[11,1]`, the position under the left
  spacebar) — to light keys `1`…`0` with the percentage.
- **Deep sleep** after 30 min idle; any key wakes it. Backlight off after 5 min.

---

## Differences from the OEM layout

If you ever fall back to the OEM quick-start guide, these are the deliberate
divergences in `nathan`:

| OEM | `nathan` |
|---|---|
| `QK_BOOT` nowhere (Esc-hold only) | `QK_BOOT` on the right half, third row down at the `/` position (`[10,4]`) — the in-keymap route to flash the right half without opening the case; plus bootmagic (`Esc`-hold at plug-in) on the left half |
| `Fn + Bksp` = factory reset, on a **tap** | factory reset is **hold-to-arm** on the base-layer `Mute` key (`[7,8]`); a tap is inert |
| Fn on the left spacebar only | Fn on **both** spacebars |
| Bottom-right order varies | `RAlt, RCmd, RCtrl, Left, Down, Right` |
| `RGB_SPD`/`RGB_VAD`/`RGB_SPI` bottom-right | `RGB_SPD` (left half) and `RGB_SPI` (right half) kept on the bottom row; `RGB_VAD`/`RGB_VAI` on the encoder under Fn; safe toggles `NK_TOGG`, `GU_TOGG`, `RGB_TOG` grouped bottom-right |
