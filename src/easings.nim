## Robert Penner Easing Functions,MIT,adapted from http://robertpenner.com/easing
import os

const headerEasings = currentSourcePath().splitPath.head / "easings.h"

func easingsLinear*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsInCubic*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsOutCubic*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsInOutCubic*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsInQuad*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsOutQuad*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsInOutQuad*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsInElastic*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsOutElastic*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsInOutElastic*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsInBounce*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsOutBounce*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsInOutBounce*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsInBack*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsOutBack*(inputFloat: cfloat): float {.importc, header: headerEasings.}
func easingsInOutBack*(inputFloat: cfloat): float {.importc, header: headerEasings.}


runnableExamples:
  echo easingsLinear(42.cfloat)
  echo easingsInCubic(42.cfloat)
  echo easingsOutCubic(42.cfloat)
  echo easingsInOutCubic(42.cfloat)
  echo easingsInQuad(42.cfloat)
  echo easingsOutQuad(42.cfloat)
  echo easingsInOutQuad(42.cfloat)
  echo easingsInElastic(42.cfloat)
  echo easingsOutElastic(42.cfloat)
  echo easingsInOutElastic(42.cfloat)
  echo easingsInBounce(42.cfloat)
  echo easingsOutBounce(42.cfloat)
  echo easingsInOutBounce(42.cfloat)
  echo easingsInBack(42.cfloat)
  echo easingsOutBack(42.cfloat)
  echo easingsInOutBack(42.cfloat)
