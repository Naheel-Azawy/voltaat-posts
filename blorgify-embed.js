function blorgify_embed(url) {
    url = url.replace(/\/(index.html)?$/, "");
    var parent = url.split("/"); parent.pop(); parent = parent.join("/");
    var el = document.getElementById("blorgify-embed");
    var xmlhttp = new XMLHttpRequest();
    var status = 0;
    xmlhttp.onreadystatechange = function() {
        if (xmlhttp.readyState == 4) {
            status = xmlhttp.status;
        }
        if (xmlhttp.readyState == 4 && status == 200) {
            var html = '<base href="' + url + '/" />\n' +
                xmlhttp.responseText;
            html = html.replace(/<h1>.+<\/h1>/, "");
            el.innerHTML = html;
            var po = document.createElement('script');
            po.type = 'text/javascript';
            po.src = parent + "/prism.js";
            document.body.appendChild(po);
        }
    };
    try {
        xmlhttp.open("GET", url, true);
        xmlhttp.send();
    } catch(err) {
        el.innerHTML = "Failed loading " + url;
    }
}
