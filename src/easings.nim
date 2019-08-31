## Robert Penner Easing Functions,MIT,adapted from http://robertpenner.com/easing
when not defined(js):
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

else:

  #func easingsLinear*(inputFloat: cfloat): float {.importc, header: headerEasings.}
  func easingsLinear*(t: float, b: float = 0.0, c: float = 1.0, d: float = 1.0): float =
    c * t / d + b

  #func easingsInCubic*(inputFloat: cfloat): float {.importc, header: headerEasings.}
  func easingsInCubic*(time: float, b: float = 0.0, c: float = 1.0, d: float = 1.0): float =
    let t = time / d
    c * t * t * t + b

  #func easingsOutCubic*(inputFloat: cfloat): float {.importc, header: headerEasings.}
  func easingsOutCubic*(time: float, b: float = 0.0, c: float = 1.0, d: float = 1.0): float =
    let t = time / d - 1
    c * (t * t * t + 1) + b

  #func easingsInOutCubic*(inputFloat: cfloat): float {.importc, header: headerEasings.}
  func easingsInOutCubic*(time: float, b: float = 0.0, c: float = 1.0, d: float = 1.0): float =
      var t = time / (d * 2)
      if t < 1:
        result = c / 2 * t * t * t + b
      else:
        t -= 2
      result =  c / 2 * (t * t * t + 2) + b

  #func easingsInQuad*(inputFloat: cfloat): float {.importc, header: headerEasings.}
  func easingsInQuad*(time: float, b: float = 0.0, c: float = 1.0, d: float = 1.0): float =
    let t =  time / d
    result =  -c * t * (t - 2) + b

  func easingsOutQuad*(inputFloat: cfloat): float =
    result = 0.0
  func easingsInOutQuad*(inputFloat: cfloat): float =
    result = 0.0
  func easingsInElastic*(inputFloat: cfloat): float =
    result = 0.0
  func easingsOutElastic*(inputFloat: cfloat): float =
    result = 0.0
  func easingsInOutElastic*(inputFloat: cfloat): float =
    result = 0.0
  func easingsInBounce*(inputFloat: cfloat): float =
    result = 0.0
  func easingsOutBounce*(inputFloat: cfloat): float =
    result = 0.0
  func easingsInOutBounce*(inputFloat: cfloat): float =
    result = 0.0
  func easingsInBack*(inputFloat: cfloat): float =
    result = 0.0
  func easingsOutBack*(inputFloat: cfloat): float =
    result = 0.0
  func easingsInOutBack*(inputFloat: cfloat): float =
    result = 0.0


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


when isMainModule:
  assert easingsLinear(42) == 42.0
  assert easingsInCubic(42) == 74088.0
  assert easingsOutCubic(42) == 68922.0
  echo easingsInOutCubic(42)
  assert easingsInOutCubic(42.cfloat) == 275685.0
  echo easingsInQuad(42)
  assert easingsInQuad(42.cfloat) == 1764.0
  assert easingsOutQuad(42.cfloat) == -1680.0
  assert easingsInOutQuad(42.cfloat) == -3361.0
  echo easingsInElastic(42.cfloat)
  assert easingsOutElastic(42.cfloat) == 1.0
  assert easingsInOutElastic(42.cfloat) == 1.0
  assert easingsInBounce(42.cfloat) == -12711.5625
  assert easingsOutBounce(42.cfloat) == 12741.7509765625
  assert easingsInOutBounce(42.cfloat) == 25454.3125
  assert easingsInBack(42.cfloat) == 197153.078125
  assert easingsOutBack(42.cfloat) == 189056.96875
  assert easingsInOutBack(42.cfloat) == 1366635.0
