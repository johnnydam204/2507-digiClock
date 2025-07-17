idf_component_register(
    SRCS    
        "src/inf_7seg_disp.c"
        # "src/hal_i2c.c"            
    INCLUDE_DIRS "inc"
    REQUIRES bsp
)