{
    "targets": [
        {
            "target_name": "sankyo-ict3k",
            "sources": [ "./src/sankyo-ict3k.cc", "./src/functions.cc" ],
            "include_dirs" : [
 	 			"<!(node -e \"require('nan')\")"
			],
            'libraries' : [
                "<(module_root_dir)/lib/ICT3K5_6240DLL.lib"
            ]
        }
    ],
}