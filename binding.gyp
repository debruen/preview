{
    "targets": [{
        "target_name": "program",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        'conditions': [
            ['OS=="mac"', {
                'xcode_settings': {
                    '-std': 'c++11',
                    '-stdlib': 'libc++',
                    'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
                    'MACOSX_DEPLOYMENT_TARGET': '12.1'
                }
            }]
        ],
        "sources": [
            "cpp/main.cpp",

            # program
            "cpp/src/program.cpp"

        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",
            "/usr/include/lib",
            "/opt/homebrew/lib",
            "/opt/homebrew/include/",
            "/opt/homebrew/include/opencv4"
        ],
        'libraries': [
            '-L/opt/homebrew/lib',
            '-lopencv_core',
            '-lopencv_imgproc',
            '-lopencv_highgui',
            '-lpng',
            '-ltiff',
            '-ljpeg',
            '-lstk',
            '-lrtaudio',
            '-lfftw3'
        ],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}
