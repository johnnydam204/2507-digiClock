idf_component_register(
    SRCS    
        # "src/bsp_ds3231.c"
        "src/bsp_led7seg.c"
        "src/bsp_74hc595.c"          
    INCLUDE_DIRS "inc"
    REQUIRES hals
)