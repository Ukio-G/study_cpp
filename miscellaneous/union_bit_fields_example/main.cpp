#include <iostream>
#include <cstdint> 
union MyUnion {
    uint8_t byte[4];
    uint32_t dword;
    struct {
        uint8_t A : 1;
        uint8_t B : 1;
        uint8_t C : 1;
        uint8_t D : 1;
        uint8_t E : 1;
        uint8_t F : 1;
        uint8_t G : 1;
        uint8_t H : 1;
    } char_data;
};

union PositionOffset{
    uint8_t data;
    struct {
       bool sign_x : 1;
       bool sign_y : 1;
       uint8_t x_offset : 3;
       uint8_t y_offset : 3;
    };
};


union TestUnion{

    uint8_t data[2];

    struct 
    {
        bool A : 1;
        bool B : 1;
        bool C : 1;
        bool D : 1;
        uint8_t byte : 8;
        uint8_t half_byte : 4;
    };

};

#pragma pack(push, 1)
union obj_data_u
{
    uint8_t data[8];
    struct {
        bool mode : 1;
        uint16_t x_p :13;
        uint16_t y_p :13;
        uint16_t speed :11;
        uint16_t heading :11;
        uint8_t obj_len :7;
        uint8_t obj_id :8;
    };
};
#pragma push(pop)

int main(int argc, char *argv[]) {
    MyUnion * my = new MyUnion;

    my->dword = 0;

    std::cout << (int)my->byte[0] << std::endl;
    std::cout << (int)my->byte[1] << std::endl;
    std::cout << (int)my->byte[2] << std::endl;
    std::cout << (int)my->byte[3] << std::endl;

    my->byte[0] = 255 - 128 - 8 - 2;

    std::cout << my->dword << std::endl;
    
    std::cout << (int)my->char_data.A << std::endl;
    std::cout << (int)my->char_data.B << std::endl;
    std::cout << (int)my->char_data.C << std::endl;
    std::cout << (int)my->char_data.D << std::endl;
    std::cout << (int)my->char_data.E << std::endl;
    std::cout << (int)my->char_data.F << std::endl;
    std::cout << (int)my->char_data.G << std::endl;
    std::cout << (int)my->char_data.H << std::endl;

    PositionOffset p_offset = {std::atoi(argv[argc-1])};

    std::cout << "sign_x "  << (int)p_offset.sign_x << std::endl;
    std::cout << "sign_y " << (int)p_offset.sign_y << std::endl;
    std::cout << "x_offset " << (int)p_offset.x_offset << std::endl;
    std::cout << "y_offset "  << (int)p_offset.y_offset << std::endl;


    TestUnion u_test = {0b11111111, 0b00010000};

    std::cout << (unsigned int) u_test.byte << std::endl;
    std::cout << (unsigned int) u_test.half_byte << std::endl;

    obj_data_u u_obj = {0b01001000,0b00100010,0x00,0b00100100,0xe6,0x01,0x1a,0x32};

    std::cout << (int) u_obj.mode << std::endl;
    std::cout << (int) u_obj.x_p << std::endl;
    std::cout << (int) u_obj.y_p << std::endl;
    std::cout << (int) u_obj.speed << std::endl;
    std::cout << (int) u_obj.heading << std::endl;
    std::cout << (int) u_obj.obj_len << std::endl;
    std::cout << (int) u_obj.obj_id << std::endl;



    return 0;
}
