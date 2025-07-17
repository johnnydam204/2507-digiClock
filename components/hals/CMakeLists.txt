idf_component_register(
    SRCS    
        "src/hal_gpio.c"
        # "src/hal_i2c.c"            
    INCLUDE_DIRS "inc"
    REQUIRES config
)