#include <math.h>

float easingsLinear(float t);
float easingsInCubic(float t);
float easingsOutCubic(float t);
float easingsInOutCubic(float t);
float easingsInQuad(float t);
float easingsOutQuad(float t);
float easingsInOutQuad(float t);
float easingsInElastic(float t);
float easingsOutElastic(float t);
float easingsInOutElastic(float t);
float easingsInBounce(float t);
float easingsOutBounce(float t);
float easingsInOutBounce(float t);
float easingsInBack(float t);
float easingsOutBack(float t);
float easingsInOutBack(float t);

#define INTERNAL_PI (3.141592653589793)
#define INTERNAL_MIN(a, b) (a > b ? b : a)
#define INTERNAL_MAX(a, b) (a > b ? a : b)
#define INTERNAL_CLAMP(v, lo, hi) INTERNAL_MAX(lo, INTERNAL_MIN(hi, v))
#define INTERNAL_SWAP(T, A, B) { T tmp = B; B = A; A = tmp; }
#define INTERNAL_SQR(a) ((a) * (a))

float internal_easings__linear(float t, float b, float c, float d) {
    return c * t / d + b;
}

float internal_easings__in_cubic(float t, float b, float c, float d) {
    t /= d;
    return c * t * t * t + b;
}

float internal_easings__out_cubic(float t, float b, float c, float d) {
    t = t / d - 1;
    return c * (t * t * t + 1) + b;
}

float internal_easings__in_out_cubic(float t, float b, float c, float d) {
    t /= d / 2;
    if (t < 1) {
        return c / 2 * t * t * t + b;
    }
    t -= 2;
    return c / 2 * (t * t * t + 2) + b;
}

float internal_easings__in_quad(float t, float b, float c, float d) {
    t /= d;
    return c * t * t + b;
}

float internal_easings__out_quad(float t, float b, float c, float d) {
    t /= d;
    return -c * t * (t - 2) + b;
}

float internal_easings__in_out_quad(float t, float b, float c, float d) {
    t /= d / 2;
    if (t < 1) {
        return c / 2 * t * t + b;
    }
    --t;
    return -c / 2 * (t * (t - 2) - 1) + b;
}

float internal_easings__in_quart(float t, float b, float c, float d) {
    t /= d;
    return c * t * t * t * t + b;
}

float internal_easings__out_quart(float t, float b, float c, float d) {
    t = t / d - 1;
    return -c * (t * t * t * t - 1) + b;
}

float internal_easings__in_out_quart(float t, float b, float c, float d) {
    t /= d / 2;
    if (t < 1) {
        return c / 2 * t * t * t * t + b;
    }
    t -= 2;
    return -c / 2 * (t * t * t * t - 2) + b;
}

float internal_easings__in_quint(float t, float b, float c, float d) {
    t /= d;
    return c * t * t * t * t * t + b;
}

float internal_easings__out_quint(float t, float b, float c, float d) {
    t = t / d - 1;
    return c * (t * t * t * t * t + 1) + b;
}

float internal_easings__in_out_quint(float t, float b, float c, float d) {
    t /= d / 2;
    if (t < 1) {
        return c / 2 * t * t * t * t * t + b;
    }
    t -= 2;
    return c / 2 * (t * t * t * t * t + 2) + b;
}

float internal_easings__in_sine(float t, float b, float c, float d) {
    return -c * cos(t / d * (INTERNAL_PI / 2)) + c + b;
}

float internal_easings__out_sine(float t, float b, float c, float d) {
    return c * sin(t / d * (INTERNAL_PI / 2)) + b;
}

float internal_easings__in_out_sine(float t, float b, float c, float d) {
    return -c / 2 * (cos(INTERNAL_PI * t / d) - 1) + b;
}

float internal_easings__in_out_expo(float t, float b, float c, float d) {
    t /= d / 2;
    if (t < 1) {
        return c / 2 * pow(2, 10 * (t - 1)) + b;
    }
    return c / 2 * (-pow(2, -10 * --t) + 2) + b;
}

float internal_easings__in_circ(float t, float b, float c, float d) {
    t /= d;
    return -c * (sqrt(1 - t * t) - 1) + b;
}

float internal_easings__out_circ(float t, float b, float c, float d) {
    t = t / d - 1;
    return c * sqrt(1 - t * t) + b;
}

float internal_easings__in_out_circ(float t, float b, float c, float d) {
    t /= d / 2;
    if (t < 1) {
        return -c / 2 * (sqrt(1 - t * t) - 1) + b;
    }
    t -= 2;
    return c / 2 * (sqrt(1 - t * t) + 1) + b;
}

float internal_easings__in_elastic(float t, float b, float c, float d) {
    float a, p, s;
    s = 1.70158;
    p = 0;
    a = c;
    if (!p) {
        p = d * 0.3;
    }
    if (a < fabsf(c)) {
        a = c;
        s = p / 4;
    } else {
        s = p / (2 * INTERNAL_PI) * asin(c / a);
    }
    t -= 1;
    return -(a * pow(2, 10 * t) *
             sin((t * d - s) * (2 * INTERNAL_PI) / p)) + b;
}

float internal_easings__out_elastic(float t, float b, float c, float d) {
    float a, p, s;
    s = 1.70158;
    p = 0;
    a = c;
    if (!p) {
        p = d * 0.3;
    }
    if (a < fabsf(c)) {
        a = c;
        s = p / 4;
    } else {
        s = p / (2 * INTERNAL_PI) * asin(c / a);
    }
    return a * pow(2, -10 * t) *
           sin((t * d - s) * (2 * INTERNAL_PI) / p) + c + b;
}

float internal_easings__in_out_elastic(float t, float b, float c, float d) {
    float a, p, s;
    s = 1.70158;
    p = 0;
    a = c;
    if (!p) {
        p = d * (0.3 * 1.5);
    }
    if (a < fabsf(c)) {
        a = c;
        s = p / 4;
    } else {
        s = p / (2 * INTERNAL_PI) * asin(c / a);
    }
    if (t < 1) {
        t -= 1;
        return -0.5 * (a * pow(2, 10 * t) *
                       sin((t * d - s) * (2 * INTERNAL_PI) / p)) + b;
    }
    t -= 1;
    return a * pow(2, -10 * t) *
           sin((t * d - s) * (2 * INTERNAL_PI) / p) * 0.5 + c + b;
}

float internal_easings__in_back(float t, float b, float c, float d) {
    float s = 1.70158;
    t/=d;
    return c*t*t*((s+1)*t - s) + b;
}

float internal_easings__out_back(float t, float b, float c, float d) {
    float s = 1.70158;
    t=t/d-1;
    return c*(t*t*((s+1)*t + s) + 1) + b;
}

float internal_easings__in_out_back(float t, float b, float c, float d) {
    float s = 1.70158;
    t/=d/2;
    s*=1.525;
    if (t < 1) {
        return c/2*(t*t*((s+1)*t - s)) + b;
    }
    s*=1.525;
    t-=2;
    return (c/2*(t*t*(s+1)*t + s) + 2) + b;
}

float internal_easings__out_bounce(float t, float b, float c, float d);

float internal_easings__in_bounce(float t, float b, float c, float d) {
    float v = internal_easings__out_bounce(d - t, 0, c, d);
    return c - v + b;
}

float internal_easings__out_bounce(float t, float b, float c, float d) {
    t /= d;
    if (t < 1.0 / 2.75) {
        return c * (7.5625 * t * t) + b;
    }
    if (t < 2.0 / 2.75) {
        t -= 1.5 / 2.75;
        return c * (7.5625 * t * t + 0.75) + b;
    }
    if (t < 2.5 / 2.75) {
        t -= 2.25 / 2.75;
        return c * (7.5625 * t * t + 0.9375) + b;
    }
    t -= 2.625 / 2.75;
    return c * (7.5625 * t * t + 0.984375) + b;
}

float internal_easings__in_out_bounce(float t, float b, float c, float d) {
    float v;
    if (t < d / 2) {
        v = internal_easings__in_bounce(t * 2, 0, c, d);
        return v * 0.5 + b;
    }
    v = internal_easings__out_bounce(t * 2 - d, 0, c, d);
    return v * 0.5 + c * 0.5 + b;
}

float easingsLinear(float t) {
    return internal_easings__linear(t, 0, 1, 1);
}

float easingsInCubic(float t) {
    return internal_easings__in_cubic(t, 0, 1, 1);
}

float easingsOutCubic(float t) {
    return internal_easings__out_cubic(t, 0, 1, 1);
}

float easingsInOutCubic(float t) {
    return internal_easings__in_out_cubic(t, 0, 1, 1);
}

float easingsInQuad(float t) {
    return internal_easings__in_quad(t, 0, 1, 1);
}

float easingsOutQuad(float t) {
    return internal_easings__out_quad(t, 0, 1, 1);
}

float easingsInOutQuad(float t) {
    return internal_easings__in_out_quad(t, 0, 1, 1);
}

float easingsInElastic(float t) {
    return internal_easings__in_elastic(t, 0, 1, 1);
}

float easingsOutElastic(float t) {
    return internal_easings__out_elastic(t, 0, 1, 1);
}

float easingsInOutElastic(float t) {
    return internal_easings__in_out_elastic(t, 0, 1, 1);
}

float easingsInBounce(float t) {
    return internal_easings__in_bounce(t, 0, 1, 1);
}

float easingsOutBounce(float t) {
    return internal_easings__out_bounce(t, 0, 1, 1);
}

float easingsInOutBounce(float t) {
    return internal_easings__in_out_bounce(t, 0, 1, 1);
}

float easingsInBack(float t) {
    return internal_easings__in_back(t, 0, 1, 1);
}

float easingsOutBack(float t) {
    return internal_easings__out_back(t, 0, 1, 1);
}

float easingsInOutBack(float t) {
    return internal_easings__in_out_back(t, 0, 1, 1);
}
