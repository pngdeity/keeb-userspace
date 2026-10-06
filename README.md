# keeb-userspace

External QMK userspace for the EPOMAKER Split65 (WB32FQ95). Holds the personal
`nathan` keymap, kept **outside** the firmware tree so that re-pinning the
`qmk_firmware` submodule cannot conflict with it.

## Layout

| Path | Purpose |
|------|---------|
| `keyboards/epomaker/epomaker_split65/keymaps/nathan/` | The personal `nathan` keymap (`keymap.c`, `rules.mk`). **`keymap.md` documents the whole layout** — read that, not the OEM manual. |

## Build

Point the firmware repo's build at this userspace with `QMK_USERSPACE`. The
firmware project's `bin/make` wrapper supplies it automatically:

```sh
# from the keeb project root
./bin/make epomaker/epomaker_split65:nathan
```

Never commit built artifacts (`*.bin`); they are gitignored.
