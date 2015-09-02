<?php

function chapter_welcome_greeting(){
    $content = array();
    global $user;

    if($user->uid == 0) {
        _chapter_welcome_load_greeting(1, $content);

        return $content;
    }
    else {
        //if user has role 3, user is an admin
        //else he must be an authenticated user (chapter)
        if(user_has_role(3)){
            _chapter_welcome_load_greeting(3, $content);

            return $content;
        }
        else{
            _chapter_welcome_load_greeting(2, $content);

            return $content;
        }
    }

    return $content;
}

function _chapter_welcome_load_greeting($role, &$content){
    global $user;
    dsm($user);
    switch($role){
        case 1: //anonymous user
            $content['raw_markup'] = array(
                '#type' => 'markup',
                '#markup' => t('
                    Welcome to the Hermano Database application! Here you can search
                    for Hermanos from all over the country! Through our search engine
                    you can search by region, chapter, name, pledge semester, pledge year,
                    school, work field, major, etc.
                '),
                '#prefix' => '<p>',
                '#suffix' => '</p>',
            );
            break;
        case 2: //chapter user (authenticated)
            $content['raw_markup'] = array(
                '#type' => 'markup',
                '#markup' => t('
                    Greetings %user! Welcome back to your chapter\'s Hermano Database. Below
                    you can see navigation to see your current roster. Here you can update,
                    add, or remove information pertaining to any individual Hermano. You can also
                    update your Chapter Profile as well!
                ', array('%user' => $user->name)),
                '#prefix' => '<p>',
                '#suffix' => '</p>',
            );
            break;
        case 3: //admin user
            $content['raw_markup'] = array(
                '#type' => 'markup',
                '#markup' => t('
                    Welcome %admin! Welcome to the adminstrative panel of the LUL\'s Hermano\'s
                    Database. Here you can review your users and content of the entire website
                    You can also create a new user for a new chapter.
                ', array('%admin' => $user->name)),
                '#prefix' => '<p>',
                '#suffix' => '</p>',
            );
            break;


    }

}