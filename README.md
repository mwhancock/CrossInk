# CrossHarbor

Community-focused firmware fork for the Xteink X3/X4 based on **[CrossInk](https://github.com/uxjulia/crossink)**, with selected ideas from **[CrossCover](https://github.com/StefanTsonev/CrossCover)** for integration with **[Hardcover.app](https://hardcover.app/)**.

## Goal and scope

CrossHarbor aims to build upon the CrossInk reading experience and stability, while adding practical Hardcover tracking workflows for daily use on constrained hardware.

In scope:
- Keep changes narrow, readable, and maintainable.
- Prioritize features that materially improve focused reading on-device.
- Add lightweight Hardcover features (status/progress/rating/linking) that support reading flow without turning the firmware into a full social/discovery client.

Out of scope:
- Full rewrites of core architecture.
- Feature additions that add heavy always-on networking or broad non-reading surface area.
- Heavy Hardcover social/discovery surfaces that do not directly improve the core reading loop.

## Roadmap (near-term)

- Home-screen quick Hardcover status action (without entering the reader menu).
- One-tap status cycle action for linked books (`Want → Reading → Paused → Read`).
- Lightweight offline sync queue for failed Hardcover writes, with retry when connectivity returns.
- Progress sync throttling to reduce network/memory churn while preserving useful tracking.
- Clear sync feedback in-reader (`queued`, `synced`, `failed`) without adding extra UI complexity.

## What this fork includes

### Core reader (from CrossInk)
- Typography-focused defaults (ChareInk, Lexend Deca, Bitter) and extended font sizes.
- Reader QoL additions (book options, reading stats, controls customization, bookmarks/clippings, etc.).

### CrossHarbor additions
- **EPUB memory reliability**: WiFi is disabled during chapter indexing to maximize heap on ESP32-C3, and restored on exit. Eliminates OOM crashes when opening fresh books.
- **Custom boot branding**: CrossHarbor anchor logo and name on boot and sleep screens.
- **Hardcover integration**:
  - Settings entry for Hardcover API key import + authentication.
  - Home screen entry for a Hardcover library view.
  - In-reader Hardcover menu with manual/auto book linking, mark currently reading, mark read, progress update, and rating.
  - Auto-sync on reader exit with configurable threshold.
  - Visual state indicators (`[x]` / `[ ]`) in the menu reflecting what's already set for the linked book.
- **OTA updates**: device checks for new CrossHarbor releases and flashes wirelessly via Settings → Check for Updates.

## Branches

| Branch | Purpose |
|--------|---------|
| `main` | Stable releases. Safe for daily use. |
| `beta` | Pre-release. New features, more testing needed. |

## Hardcover quick setup

1. Put your token in:

```text
/.crosspoint/hardcover_token.txt
```

2. On device:

```text
Settings > Hardcover > Import API Key
Settings > Hardcover > Authenticate
```

3. Open a book, then:

```text
Reader Menu > Hardcover
```

## Build and flash

Build:

```sh
pio run -e default
```

Flash directly:

```sh
pio run -e default -t upload
```

Or download a pre-built `.bin` from the [Releases](../../releases) page and flash it via the web installer or SD card.

If submodules are missing, run:

```sh
git submodule sync --recursive
git submodule update --init --recursive
```

## Contributing

Contributions are welcome! A few guidelines to keep things tidy:

- **Keep PRs narrow.** One feature or fix per PR. Avoid bundling unrelated cleanup.
- **No architecture rewrites.** The Activity system, HAL, and renderer are out of scope for change.
- **Memory matters.** This runs on ESP32-C3 with ~380 KB RAM and no PSRAM. Explain any new heap allocation and prefer stack or static storage where practical. See `AGENTS.md` for the full resource rules.
- **Test on hardware.** Simulator builds are useful for fast iteration but real hardware is required before merging anything reader or memory-sensitive.
- **Follow the commit style:** `type: short summary` (e.g. `fix:`, `feat:`, `chore:`, `docs:`).
- **Update `CHANGELOG.md`** with a human-readable entry for any user-visible change.

If you're unsure whether an idea fits the scope, open an issue first.

## Credits

- **CrossInk** — primary upstream firmware base and ongoing architecture.
- **CrossCover** — reference for Hardcover integration patterns and UX ideas.
- **CrossPoint Reader community** and contributors across upstream projects.

CrossHarbor's integration and iteration work was completed with assistance from AI tooling (code exploration, implementation support, and debugging workflows).

