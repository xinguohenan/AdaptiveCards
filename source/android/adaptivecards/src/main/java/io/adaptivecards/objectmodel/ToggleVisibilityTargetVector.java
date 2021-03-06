/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package io.adaptivecards.objectmodel;

public class ToggleVisibilityTargetVector {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected ToggleVisibilityTargetVector(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(ToggleVisibilityTargetVector obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        AdaptiveCardObjectModelJNI.delete_ToggleVisibilityTargetVector(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public ToggleVisibilityTargetVector() {
    this(AdaptiveCardObjectModelJNI.new_ToggleVisibilityTargetVector__SWIG_0(), true);
  }

  public ToggleVisibilityTargetVector(long n) {
    this(AdaptiveCardObjectModelJNI.new_ToggleVisibilityTargetVector__SWIG_1(n), true);
  }

  public long size() {
    return AdaptiveCardObjectModelJNI.ToggleVisibilityTargetVector_size(swigCPtr, this);
  }

  public long capacity() {
    return AdaptiveCardObjectModelJNI.ToggleVisibilityTargetVector_capacity(swigCPtr, this);
  }

  public void reserve(long n) {
    AdaptiveCardObjectModelJNI.ToggleVisibilityTargetVector_reserve(swigCPtr, this, n);
  }

  public boolean isEmpty() {
    return AdaptiveCardObjectModelJNI.ToggleVisibilityTargetVector_isEmpty(swigCPtr, this);
  }

  public void clear() {
    AdaptiveCardObjectModelJNI.ToggleVisibilityTargetVector_clear(swigCPtr, this);
  }

  public void add(ToggleVisibilityTarget x) {
    AdaptiveCardObjectModelJNI.ToggleVisibilityTargetVector_add(swigCPtr, this, ToggleVisibilityTarget.getCPtr(x), x);
  }

  public ToggleVisibilityTarget get(int i) {
    long cPtr = AdaptiveCardObjectModelJNI.ToggleVisibilityTargetVector_get(swigCPtr, this, i);
    return (cPtr == 0) ? null : new ToggleVisibilityTarget(cPtr, true);
  }

  public void set(int i, ToggleVisibilityTarget val) {
    AdaptiveCardObjectModelJNI.ToggleVisibilityTargetVector_set(swigCPtr, this, i, ToggleVisibilityTarget.getCPtr(val), val);
  }

}
