package com.testt;

import java.util.ArrayList;
import java.util.List;


public class Main {
    public static double realFunc(double x) {
        return x * Math.exp(0.5D * x) + 1.2D * x - 5.0D;
    }

    public static double derrivative(double x) {
        return Math.sin(x);
    }
  
    public static void bisection(double a, double b, int iterate) {
        for(int i = 0; i < iterate; ++i) {
            double cur = (b - a) / 2.0D;
            System.out.print(cur - a);
            if (realFunc(cur) * realFunc(a) > 0.0D) {
                a = cur;
            } else {
                b = cur;
            }
        }

    }

    public static void falsePosition(double l, double r, int iterate) {
        for(int i = 0; i < iterate; ++i) {
            double cur = (l * realFunc(r) - r * realFunc(l)) / (realFunc(r) - realFunc(l));
            System.out.println("x: " + cur + "    f(x): " + realFunc(cur));
            if (realFunc(cur) * realFunc(l) > 0.0D) {
                l = cur;
            } else {
                r = cur;
            }
        }

    }
    
     public static double fixedPointEstimate(double x) {
        return 5.0D / (Math.exp(0.5D * x) + 1.2D);
    }

    public static void fixedPoint(double xi, int iterate) {
        double cur = xi;

        for(int i = 0; i < iterate; ++i) {
            System.out.print("x " + cur);
            System.out.print("  y: " + realFunc(cur));
            System.out.println("    error:" + (fixedPointEstimate(cur) - cur) / fixedPointEstimate(cur));
            cur = fixedPointEstimate(cur);
        }

    }

    public static void newtonRaphson(double xi, int iterate) {
        double cur = xi;

        for(int i = 0; i < iterate; ++i) {
            System.out.println("x: " + cur + "    f(x): " + realFunc(cur));
            cur -= realFunc(cur) / derrivative(cur);
        }

    }
    public static void main(String[] args) {
        fixedPoint(1.0D, 7);
    }

}
