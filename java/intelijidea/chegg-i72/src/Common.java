public interface Common {
    /**
     * Whether or not this freezer requires a water-line hookup.
     * @return true if the freezer uses water
     */
    public boolean needsWater();

    /**
     * Whether or not this freezer requires an electrical hookup.
     * @return true if the freezer uses electricity
     */
    public boolean needsElectricity();

    /**
     * Return the dimensions of this Freezer in feet as a
     * @return dimensions
     */
    public String size();
}
