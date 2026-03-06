# calc-math

Header-only библиотека операций над `long long` с кодами ошибок.

**Функции (возвращают `calc_math::MathCode`, результат — в `out`):**

* `add(a, b, out)`, `sub(a, b, out)`, `mul(a, b, out)`, `div(a, b, out)`
* `pow(base, exp, out)` — итеративно, `exp >= 0`
* `fact(n, out)` — рекурсивно, `n >= 0`

**Коды:**
`OK`, `OVERFLOW`, `DIV_BY_ZERO`, `INVALID_INPUT`

## Include

```cpp id="6y3f16"
#include "calc_math.h"
```

## CMake FetchContent (пример)

```cmake id="wp0rq2"
FetchContent_Declare(calc_math
  GIT_REPOSITORY `https://github.com/AgapeColor/calc-math.git`
  GIT_TAG main
)
FetchContent_MakeAvailable(calc_math)
target_link_libraries(calc PRIVATE calc_math)
```
