idf_component_register(
    SRCS    
        "src/inf_display.c"
        # "src/hal_i2c.c"            
    INCLUDE_DIRS 
        "inc"
    REQUIRES 
        "bsp"
)