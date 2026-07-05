#include "BootActivity.h"

#include <GfxRenderer.h>
#include <I18n.h>

#include "AppVersion.h"
#include "fontIds.h"
#include "images/HarborAnchor120.h"

void BootActivity::onEnter() {
  Activity::onEnter();

  const auto pageWidth = renderer.getScreenWidth();
  const auto pageHeight = renderer.getScreenHeight();

  renderer.clearScreen();
  renderer.drawImage(HarborAnchor120, (pageWidth - HARBORANCHOR120_WIDTH) / 2, (pageHeight - HARBORANCHOR120_HEIGHT) / 2,
                     HARBORANCHOR120_WIDTH, HARBORANCHOR120_HEIGHT);
  renderer.drawCenteredText(UI_10_FONT_ID, pageHeight / 2 + 70, tr(STR_CROSSHARBOR), true, EpdFontFamily::BOLD);
  renderer.drawCenteredText(SMALL_FONT_ID, pageHeight / 2 + 95, tr(STR_BOOTING));
  renderer.drawCenteredText(SMALL_FONT_ID, pageHeight - 30, CROSSINK_VERSION);
  renderer.displayBuffer();
}
