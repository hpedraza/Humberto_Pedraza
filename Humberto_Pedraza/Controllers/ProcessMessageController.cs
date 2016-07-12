using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Humberto_Pedraza.Controllers
{
    public class ProcessMessageController : Controller
    {
        // GET: ProcessMessage
        public ActionResult Index()
        { 
        
            //  check what is being posted, to make sure nothing bad is being sent to the returened view
            // can do so by using request array or by creating an object model that reflects the contact form


            return View();
        }
    }
}