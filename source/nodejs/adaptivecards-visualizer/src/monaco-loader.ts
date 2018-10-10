import * as monaco from 'monaco-editor';

export var editor: any;

export function loadMonacoEditor(jsonSchema, callback) {
    if (jsonSchema) {
        var config = {
            schemas: [
                {
                    uri: "http://adaptivecards.io/schemas/adaptive-card.json",
                    schema: jsonSchema,
                    fileMatch: ["*"],
                }
            ],
            validate: false,
            allowComments: true
        }

        monaco.languages.json.jsonDefaults.setDiagnosticsOptions(config);
    }

    editor = monaco.editor.create(
        document.getElementById('editor'),
        {
            folding: true,
//            validate: false,
            fontSize: 13.5,
            language: 'json',
            minimap: {
                enabled: false
            }
        }
    );

    window.addEventListener('resize', function () {
        editor.layout();
    });

    //monacoEditor.layout();

    callback();
}
